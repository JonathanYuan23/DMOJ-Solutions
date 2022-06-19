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

const int MOD = 1000000007, INF = 0x3f3f3f3f, MX = 500005, IMX = INT_MAX, IMN = INT_MIN;
const long long LLMX = LONG_LONG_MAX, LLMN = LONG_LONG_MIN;
const char nl = '\n';

int n, m, value[MX], disc[MX], low[MX], onstack[MX], sum[MX], group[MX], id, tim; 
vi adj[MX], adj2[MX];
stack<int> st; 
pii dp[MX][2];

void dfs(int u){
    disc[u] = low[u] = ++tim;
    st.push(u); onstack[u] = 1;
    for(auto &v: adj[u]){
        if(disc[v] == -1){
            dfs(v);
            low[u] = min(low[u], low[v]);
        }
        else if(onstack[v]){
            low[u] = min(low[u], disc[v]);
        }
    }
    if(disc[u] == low[u]){
        id++;
        while(1){
            int v = st.top();
            st.pop(); onstack[v] = 0;
            group[v] = id;
            sum[id] += value[v];
            if(u == v) break;
        }
    }
}

void scc(){
    ms(disc, -1); ms(low, -1); ms(onstack, 0);
    for(int i=1; i<=n; i++) if(disc[i] == -1) dfs(i);
    // rebuild
    for(int i=1; i<=n; i++){
        for(auto j: adj[i]){
            if(group[i] == group[j]) continue;
            adj2[group[i]].pb(group[j]);
        }
    }
}

void upd(pii &x, pii y){
    if(x.fi < y.fi) x = y;
    else if(x.fi == y.fi) x.se = (x.se + y.se) % MOD;
}

void dfs2(int u){
    if(dp[u][0].fi != -1) return;
    if(u == group[n]){
        dp[u][0] = {0, 1};
        dp[u][1] = {sum[u], 1};
        return;
    }
    for(auto v: adj2[u]){
        dfs2(v);
        upd(dp[u][0], dp[v][0]);
        upd(dp[u][0], dp[v][1]);
        upd(dp[u][1], {sum[u] + dp[v][0].fi, dp[v][0].se});
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL);  cout.tie(NULL); 
    cin >> n >> m;
    for(int i=1; i<=n; i++) cin >> value[i];
    for(int i=1, u, v; i<=m; i++){
        cin >> u >> v;
        adj[u].pb(v);
    }
    scc();
    memset(dp, -1, sizeof dp);
    dfs2(group[1]); upd(dp[group[1]][0], dp[group[1]][1]);
    cout << dp[group[1]][0].fi << ' ' << dp[group[1]][0].se << nl;
    return 0;
}
