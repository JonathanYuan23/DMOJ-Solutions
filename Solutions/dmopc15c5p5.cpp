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
#define MAX 200005
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

int res[MAX], subSize[MAX], chain[MAX], chainHead[MAX], position[MAX], parent[MAX], blocks[MAX], pending[MAX], arr[MAX], n, chainId = 0, pos = 0, root, segment_size;
vi graph[MAX];

int preprocess(int n) { 
    for(int i=0; i<n; i++) arr[i] = 1;
    int current_segment = -1; 
    segment_size = sqrt(n); 
    for (int i=0; i<n; i++) { 
        if (i % segment_size == 0) { 
            current_segment++;  
        } 
        blocks[current_segment] += arr[i]; 
    } 
    return segment_size;
}

int query(int l, int r) { 
    ll sum = 0; 
    while (l < r && l % segment_size != 0) { 
        sum = ((sum % MOD + arr[l] % MOD) + pending[l/segment_size] % MOD) % MOD; 
        l++; 
    } 
    while (l + segment_size <= r) {  
        sum = (sum % MOD + blocks[l / segment_size] % MOD) % MOD; 
        l += segment_size; 
    } 
    while (l<=r) { 
        sum = ((sum % MOD + arr[l] % MOD) + pending[l/segment_size] % MOD) % MOD;  
        l++; 
    } 
    return sum; 
}

void rangeAdd(int l, int r, int val) { 

    while (l < r && l % segment_size != 0) { 
        arr[l] = (arr[l] % MOD + val % MOD) % MOD; 
        l++; 
    } 
    while (l + segment_size <= r) {  
        blocks[l / segment_size] = (blocks[l / segment_size] % MOD + val % MOD) % MOD; 
        pending[l / segment_size] = (pending[l / segment_size] % MOD + val % MOD) % MOD;
        l += segment_size; 
    } 
    while (l<=r) { 
        arr[l] = (arr[l] % MOD + val % MOD) % MOD; 
        l++; 
    } 
}

void process(int node, int par){
    parent[node] = par;
    subSize[node] += 1;
    for(auto to: graph[node]){
        if(to!=par){
            process(to, node);
            subSize[node] += subSize[to];
        }
    }
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
}

void update(int from, int to, int val){
    int curr = from, ans = 0;
    while(chain[curr] != chain[to]){
        rangeAdd(position[chainHead[chain[curr]]], position[curr], val);
        curr = parent[chainHead[chain[curr]]];
    }
    rangeAdd(position[to], position[curr], val);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL);  cout.tie(NULL);
    cin >> n;
    for(int i=1, v; i<=n; i++){
        arr[i] = 1;
        cin >> v;
        if(!v){
            root = i;
            continue;
        }
        graph[i].pb(v);
        graph[v].pb(i);
    }
    process(root, -1);
    HLD(root, -1);
    chainHead[0] = root;
    preprocess(n);
    for(int i=1, v; i<=n; i++){
        cin >> v;
        res[v] = query(position[v], position[v]);
        if(v!=root) update(parent[v], root, res[v]);
    }
    for(int i=1; i<=n; i++) cout << res[i] << ' ';
    
    return 0;
}
