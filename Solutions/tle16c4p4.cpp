#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize "Ofast"
#define frein freopen("input.txt", "r", stdin)
#define freout freopen("output.txt", "w", stdout)
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define nl '\n'
#define fi first
#define se second
#define INF 0x3f3f3f3f
#define MAX 100005
#define IMX INT_MAX
#define IMN INT_MIN
#define LLMX LONG_LONG_MAX
#define LLMN LONG_LONG_MIN
#define pb push_back
#define pf push_front
#define LSB(x) (x & (-x))
#define sz(x) (ll)(x.size())
#define umap unordered_map
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<pii, pii> piiii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<piii> viii;
typedef vector<piiii> viiii;  

ll N, M, Q, start, farthest, maxd, center, rad, dis[MAX], vis[MAX], pre[MAX];
vii adj[MAX];
vector<ll> centers;

void dfs(int cur, int par, ll mx){
    dis[cur]=mx;
    vis[cur]=1;
    if(mx>maxd){
        maxd=mx;
        farthest=cur;
    }
    for(auto x: adj[cur]){
        if(x.fi!=par){
            pre[x.fi]=cur;
            dfs(x.fi, cur, mx+x.se);
        }
    }
}

ll findDiameter(int node){
    maxd = INT_MIN;
    dfs(node, -1, 0);
    start = farthest, maxd = INT_MIN;
    dfs(farthest, -1, 0);
    return maxd;
}

void findCenter(int node){
    maxd=INT_MIN;
    dfs(node, -1, 0);
    maxd=INT_MIN; start=farthest;
    dfs(farthest, -1, 0);
    rad=dis[farthest]; 
    center=node;
    for(; farthest!=start; farthest=pre[farthest]){
        if(max(maxd-dis[farthest], dis[farthest])<rad){
            center=farthest; 
            rad=max(maxd-dis[farthest], dis[farthest]);
        }
    }
    centers.pb(rad);
}

ll solve1(){
    ll height = 0, components = 0;
    for(int i=1; i<=N; i++){
        if(!vis[i]){
            height += findDiameter(i);
            components++;
        }
    }
    return height + (components-1);
}

ll solve2(){
    for(int i=1; i<=N; i++) if(!vis[i]) findCenter(i);
    sort(centers.rbegin(), centers.rend());
    return (sz(centers) == 1) ? centers[0] : max(centers[0], centers[1] + 1);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL);  cout.tie(NULL);
    cin >> N >> M >> Q;
    for(int i=0, u, v, l; i<M; i++){
        cin >> u >> v >> l;
        adj[u].pb({v, l});
        adj[v].pb({u, l});
    }
    cout << ((Q == 1) ? solve1() : solve2()) << nl;
    
    return 0;
}
