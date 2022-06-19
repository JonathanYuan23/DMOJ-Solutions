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
#define MAX 500005
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

ll N, K, inSubtree[MAX], outSubtree[MAX], inHeight[MAX], outHeight[MAX];
vii adj[MAX];
bool house[MAX];

void dfs(int node, int par){
    for(auto to: adj[node]){
        if(to.fi == par) continue;
        dfs(to.fi, node);
        if(inSubtree[to.fi] != 0 || house[to.fi]) 
            inSubtree[node] += to.se + inSubtree[to.fi];
        if(inHeight[to.fi] != 0 || house[to.fi]) 
            inHeight[node] = max(inHeight[node], inHeight[to.fi] + to.se);
    }
}

void dfs2(int node, int par){
    vector<ll> pre(sz(adj[node]));
    ll mx1 = 0, mx2 = 0, childSub = 0, childHeight = 0;
    for(int i=0; i<sz(adj[node]); i++){
        if(adj[node][i].fi != par){
            childHeight = inHeight[adj[node][i].fi];
            if(childHeight > 0 || house[adj[node][i].fi]) 
                childHeight += adj[node][i].se;
            if(childHeight >= mx1){
                mx2 = mx1;
                mx1 = childHeight;
            }
            else if(childHeight >= mx2){
                mx2 = childHeight;
            }
            childSub = inSubtree[adj[node][i].fi];
            if(childSub > 0 || house[adj[node][i].fi]) 
                childSub += adj[node][i].se;
            pre[i] = childSub;
            if(i > 0) 
                pre[i] += pre[i-1];
        }
        else{
            if(i > 0) pre[i] += pre[i-1];
        }
    }
    ll upHeight = outHeight[node], upSub = outSubtree[node];
    for(int i=0; i<sz(adj[node]); i++){
        if(adj[node][i].fi == par) continue;
        ll use = mx1;
        childHeight = inHeight[adj[node][i].fi];
        if(childHeight > 0 || house[adj[node][i].fi]) 
            childHeight += adj[node][i].se;
        if(use == childHeight) 
            use = mx2;
        if(upHeight > 0) 
            outHeight[adj[node][i].fi] = max(outHeight[adj[node][i].fi], upHeight + adj[node][i].se);
        if(use > 0) 
            outHeight[adj[node][i].fi] = max(outHeight[adj[node][i].fi], use + adj[node][i].se);
        ll siblingSum = 0;
        if(i > 0) 
            siblingSum += pre[i-1];
        if(i < sz(adj[node])-1) 
            siblingSum += pre[sz(adj[node])-1] - pre[i];
        siblingSum += upSub;
        if(siblingSum > 0) 
            outSubtree[adj[node][i].fi] += adj[node][i].se + siblingSum;
        dfs2(adj[node][i].fi, node);
    }    
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL);  cout.tie(NULL);
    cin >> N >> K;
    for(int i=0, u, v, c; i<N-1; i++){
        cin >> u >> v >> c;
        adj[u].pb({v, c});
        adj[v].pb({u, c});
    }
    for(int i=0, u; i<K; i++){
        cin >> u;
        house[u] = 1;
    }
    dfs(1, -1);
    dfs2(1, -1);
    for(int i=1; i<=N; i++) 
        cout << 2 * (inSubtree[i] + outSubtree[i]) - max(inHeight[i], outHeight[i]) << '\n';
    
    return 0;
};
