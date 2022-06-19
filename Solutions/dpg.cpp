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

const int MOD = 1000000007, INF = 0x3f3f3f3f, MX = 100005, IMX = INT_MAX, IMN = INT_MIN;
const long long LLMX = LONG_LONG_MAX, LLMN = LONG_LONG_MIN;
const char nl = '\n';

int n, m, deg[MX], dp[MX];
vi adj[MX], order;
queue<int> q;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL);  cout.tie(NULL);
    cin >> n >> m;
    for(int i=0, u, v; i<m; i++){
        cin >> u >> v;
        adj[u].pb(v);
        deg[v]++;
    }
    for(int i=1; i<=n; i++) if(!deg[i]) q.push(i);
    while(!q.empty()){
        int u = q.front(); q.pop();
        order.pb(u);
        for(auto &to: adj[u]) if(!(--deg[to])) q.push(to);
    }
    int ans = 0;
    for(auto &u: order){
        for(auto &to: adj[u]){
            dp[to] = max(dp[to], dp[u] + 1);
            ans = max(ans, dp[to]);
        }
    }
    cout << ans << nl;
    return 0;
}
