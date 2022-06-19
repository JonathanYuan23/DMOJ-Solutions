#pragma GCC optimize "Ofast"
#include <bits/stdc++.h>
using namespace std; using pii = pair<int, int>;  using piii = pair<int, pii>;  using piiii = pair<pii, pii>;  using vi = vector<int>;  using vii = vector<pii>;  using viii = vector<piii>;  using viiii = vector<piiii>; using ll = long long; using ull = unsigned long long; 
#define frein freopen("input.txt", "r", stdin)
#define freout freopen("output.txt", "w", stdout)
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define pf push_front
#define ppb pop_back
#define LSB(x) (x & (-x))
#define sz(x) (int)(x.size())
#define ms(a, b) memset(a, b, sizeof a)

const int MOD = 1000000007, INF = 0x3f3f3f3f, MX = 1000005, IMX = INT_MAX, IMN = INT_MIN;
const long long LLMX = LONG_LONG_MAX, LLMN = LONG_LONG_MIN;
const char nl = '\n';

int n, m, edges[MX * 2], disc[MX], low[MX], psa, timer; bool vis[MX];
pii vertices[MX]; vii edgelist;

void build(){
    for(int i=1; i<=n; i++) vertices[i+1].fi = vertices[i].fi + vertices[i].se;
    for(auto &edge: edgelist){
        int u = edge.fi, v = edge.se;
        edges[vertices[u].fi] = v, ++vertices[u].fi;
        edges[vertices[v].fi] = u, ++vertices[v].fi;
    }
    for(int i=1; i<=n; i++) vertices[i].fi -= vertices[i].se;
}

void dfs(int u, int p){
    vis[u] = 1, low[u] = disc[u] = ++timer;
    for(int i=vertices[u].fi; i<vertices[u].fi + vertices[u].se; i++){
        int v = edges[i];
        if(v == p) continue;
        if(vis[v]) low[u] = min(low[u], disc[v]);
        else{
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if(low[v] > disc[u]){
                // remove bridge
                edges[i] = 0;
                for(int j=vertices[v].fi; j<vertices[v].fi + vertices[v].se; j++) if(edges[j] == u) edges[j] = 0;
            }
        }
    }
}

void dfs2(int u, int p, int &counter){
    vis[u] = 1, ++counter;
    for(int i=vertices[u].fi; i<vertices[u].fi + vertices[u].se; i++){
        int v = edges[i];
        if(v == p || !v) continue;
        if(!vis[v]) dfs2(v, u, counter);
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL);  cout.tie(NULL); 
    cin >> n >> m;
    for(int i=1, u, v; i<=m; i++){
        cin >> u >> v;
        vertices[u].se++, vertices[v].se++;
        edgelist.pb({u, v});
    }
    build();
    ms(vis, 0); ms(disc, -1); ms(low, -1);
    // find bridges
    for(int i=1; i<=n; i++) if(!vis[i]) dfs(i, -1);
    // find number of towns in each component after bridges have been removed
    ms(vis, 0);
    ll combi = 0, total = (ll) n * (n - 1) / 2;
    for(int i=1; i<=n; i++){
        if(!vis[i]){
            int counter = 0; dfs2(i, -1, counter);
            combi += (ll) counter * (n - psa - counter);
            psa += counter;
        }
    }
    double ans = (double) combi / total;
    cout << fixed << setprecision(5) << ans << nl;
    return 0;
}
