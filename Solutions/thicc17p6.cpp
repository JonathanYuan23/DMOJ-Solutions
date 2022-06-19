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
#define IMX INT_MAX
#define IMN INT_MIN
#define LLMX LONG_LONG_MAX
#define LLMN LONG_LONG_MIN
#define pb push_back
#define pf push_front
#define LSB(x) (x & (-x))
#define sz(x) (int)(x.size())
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<pii, pii> piiii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<piii> viii;
typedef vector<piiii> viiii;

int N, T, sumOfAllEdges = 0, in[MAX], out[MAX];
vii adj[MAX];
vi locs;

void dfsIn(int node, int par){
    if(sz(adj[node]) == T) locs.pb(node);
    for(auto to: adj[node]){
        if(to.fi == par) continue;
        dfsIn(to.fi, node);
        in[node] = max(in[node], in[to.fi] + to.se);
    }
}

void dfsOut(int node, int par){
    int mx1 = 0, mx2 = 0;
    for(auto to: adj[node]){
        if(to.fi == par) continue;
        if(in[to.fi] + to.se >= mx1){
            mx2 = mx1;
            mx1 = in[to.fi] + to.se;
        }
        else if(in[to.fi] + to.se > mx2){
            mx2 = in[to.fi] + to.se;
        }
    }
    for(auto to: adj[node]){
        if(to.fi == par) continue;
        int use = mx1;
        if(mx1 == in[to.fi] + to.se) use = mx2;
        out[to.fi] = to.se + max(out[node], use);
        dfsOut(to.fi, node);
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL);  cout.tie(NULL);
    cin >> N >> T;
    for(int i=0, u, v, c; i<N-1; i++){
        cin >> u >> v >> c;
        adj[u].pb({v, c});
        adj[v].pb({u, c});
        sumOfAllEdges += c;
    }
    dfsIn(1, -1);
    dfsOut(1, -1);
    sort(locs.begin(), locs.end());
    for(auto loc: locs) cout << loc << ' ' << 2 * sumOfAllEdges - max(in[loc], out[loc]) << '\n';
    
    return 0;
};
