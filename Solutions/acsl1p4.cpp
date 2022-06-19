#pragma GCC optimize "Ofast"
#include <bits/stdc++.h>
using namespace std; using pii = pair<int, int>;  using piii = pair<int, pii>;  using piiii = pair<pii, pii>;  using vi = vector<int>;  using vii = vector<pii>;  using viii = vector<piii>;  using viiii = vector<piiii>; using ll = long long; using ull = unsigned long long; 
#define frein freopen("input.txt", "r", stdin)
#define freout freopen("output.txt", "w", stdout)
#define fi first
#define se second
#define pb push_back
#define pf push_front
#define ppb pop_back
#define LSB(x) (x & (-x))
#define sz(x) (int)(x.size())

const int MOD = 1000000007, INF = 0x3f3f3f3f, MX = 25, IMX = INT_MAX, IMN = INT_MIN;
const long long LLMX = LONG_LONG_MAX, LLMN = LONG_LONG_MIN;
const char nl = '\n';

int n, m, cyclic[MX], disc[MX], low[MX], Time = 0; vector<int> adj[MX]; stack<int> st; bool onstack[MX];

void dfs(int u){
    disc[u] = low[u] = ++Time;
    st.push(u); onstack[u] = 1;
    for(auto v: adj[u]){
        if(disc[v] == -1){
            dfs(v);
            low[u] = min(low[u], low[v]);
        } else if(onstack[v]){
            low[u] = min(low[u], disc[v]);
        }
    }
    if(low[u] == disc[u]){
        vi component;
        while(1){
            int v = st.top();
            st.pop(); onstack[v] = 0;
            component.pb(v);
            if(u == v) break;
        }
        if(sz(component) > 1){
            for(auto v: component) cyclic[v] = 1;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL);  cout.tie(NULL); 
    cin >> n >> m;
    for(int i=1, u, v, su, sv; i<=m; i++){
        cin >> u >> v >> su >> sv;
        (su > sv) ? adj[u].pb(v) : adj[v].pb(u);
    }
    memset(onstack, 0, sizeof onstack); memset(disc, -1, sizeof disc); memset(low, -1, sizeof low);
    for(int i=1; i<=n; i++) if(disc[i] == -1) dfs(i);
    cout << accumulate(cyclic+1, cyclic+1+n, 0) << nl;
    return 0;
}
