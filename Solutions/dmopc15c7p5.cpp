#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize "Ofast"
#define frein freopen("input.txt", "r", stdin)
#define freout freopen("output.txt", "w", stdout)
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define fi first
#define se second
#define INF 0x3f3f3f3f
#define MAX 100005
#define pb push_back
#define LSB(x) (x & (-x))
#define sz(x) (int)(x.size())
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<pii, pii> piiii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<piii> viii;
typedef vector<piiii> viiii;

/*

u - from node 
v - to node
x - lca(u, v)
f - first occurence in euler tour
l - last occurence before u in euler tour
d - distance from node to x

formulas:

u is before v in euler tour : f_v - f_x - d_u
u is after v in euler tour : 

you are forced to visit every node in the subtree of x which u belongs

therefore the formula is 2*#nodesSubtree - du + f_v - f_x

*/

int dp[20][2*MAX], idx[20][2*MAX], logt[2*MAX], dis[MAX], subSize[MAX], chain[MAX], chainHead[MAX], position[MAX], parent[MAX], chainId = 0, pos = 0, nodes, n, q, mnIndx;
vi graph[MAX], height, first, euler;

void construct(){
    int P=floor(log2(n));
    for(int i=0; i<n; i++){
        dp[0][i] = height[i];
        idx[0][i] = i;
    }
    for(int i=2; i<=n; i++) logt[i] = logt[i/2]+1;
    long long leftInterval, rightInterval;
    for(int i=1; i<=P; i++){
        for(int j=0; j+(1<<i)<=n; j++){
            leftInterval=dp[i-1][j]; rightInterval=dp[i-1][j+(1<<(i-1))];
            dp[i][j]=min(leftInterval, rightInterval);
            idx[i][j]=(leftInterval<=rightInterval) ? idx[i-1][j] : idx[i-1][j+(1<<(i-1))];
        }
    }
}

void rmq(int l, int r){
    int len = r-l+1, P=logt[len];
    long long leftInterval = dp[P][l], rightInterval = dp[P][r-(1<<P)+1];
    mnIndx=(leftInterval<=rightInterval) ? idx[P][l] : idx[P][r-(1<<P)+1];
}

void visit(int node, int depth){
    if(first[node]==-1) first[node]=euler.size();
    euler.push_back(node);
    height.push_back(depth);
}

int lcaq(int u, int v){
    int l = min(first[u], first[v]);
    int r = max(first[u], first[v]);
    rmq(l, r);
    return euler[mnIndx];
}

void process(int node, int par, int h){
    parent[node] = par;
    subSize[node] += 1;
    dis[node] = h;
    visit(node, h);
    for(auto to: graph[node]){
        if(to != par){
            process(to, node, h+1);
            subSize[node] += subSize[to];
            visit(node, h);
        }
    }
}

bool comp(const int &a, const int &b){
    return chain[a] < chain[b];
}

int bs(int node, int id){
    int lo = 0, high = graph[node].size();
    while(lo <= high){
        int mid = (lo + high) / 2;
        if(chain[graph[node][mid]] == id) return graph[node][mid];
        else if(chain[graph[node][mid]] < id) lo = mid+1;
        else high = mid-1;
    }
    return lo;
}

void HLD(int node, int par){
    int heavyChild = -1, heavySize = -1;
    chain[node] = chainId;
    position[node] = pos++;
    for(auto to: graph[node]){
        if(to!=par){
            if(subSize[to] > heavySize){
                heavySize = subSize[to];
                heavyChild = to;
            }
        }
    }
    if(heavyChild!=-1) HLD(heavyChild, node);
    for(auto to: graph[node]){
        if(to!=par && to!=heavyChild){
            chainId++;
            chainHead[chainId] = to;
            HLD(to, node);
        }
    }
    sort(graph[node].begin(), graph[node].end(), comp);
}

int query(int from, int to){
    if(!graph[to].size()) return 0;
    int curr = from;
    while(parent[chainHead[chain[curr]]] != to && chain[curr] != chain[to]) curr = parent[chainHead[chain[curr]]];
    if(parent[chainHead[chain[curr]]] == to) subSize[chainHead[chain[curr]]];
    return subSize[bs(to, chain[curr])];
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL);  cout.tie(NULL);
    cin >> nodes;
    first.assign(nodes, -1);
    for(int i=0, c, v; i<nodes; i++){
        cin >> c;
        for(int j=0; j<c; j++){
            cin >> v;
            --v;
            graph[i].pb(v);
        }
    }
    process(0, -1, 0);
    n = height.size();
    construct();
    HLD(0, -1);
    cin >> q;
    for(int i=0, u, v; i<q; i++){
        cin >> u >> v;
        --u;
        --v;
        if(u==v){
            cout << 0 << '\n';
            continue;
        }
        int lca = lcaq(u, v);
        if(first[u] < first[v]) cout << first[v] - first[lca] - (dis[u] - dis[lca]) << '\n';
        else cout << (2*query(u, lca)) - (dis[u] - dis[lca]) + (first[v] - first[lca]) << '\n';
    }
    
    return 0;
}
