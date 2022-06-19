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
#define ppf pop_front
#define LSB(x) (x & (-x))
#define sz(x) (int)(x.size())
#define ms(a, b) memset(a, b, sizeof a)

const int MOD = 1000000007, INF = 0x3f3f3f3f, MX = 300005, IMX = INT_MAX, IMN = INT_MIN;
const long long LLMX = LONG_LONG_MAX, LLMN = LONG_LONG_MIN;
const char nl = '\n';

int n, m, ans[MX];
vi adj[MX]; set<int> nodes;

void dfs(int u, int mx) {
    ans[u] = mx;
    for(auto v: adj[u]) {
        if(!ans[v]) dfs(v, mx);
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);  cout.tie(0);
    cin >> n >> m;
    for(int i=0, u, v; i<m; i++) {
        cin >> u >> v;
        adj[v].pb(u);
        nodes.insert(u); nodes.insert(v);
    }
    for(auto it = nodes.rbegin(); it != nodes.rend(); it++) {
        if(!ans[*it]) dfs(*it, *it);
    }
    bool exists = 0;
    for(auto it = nodes.rbegin(); it != nodes.rend(); it++) {
        if(ans[*it] > *it){
            cout << *it << ' ' << ans[*it] << nl;
            exists = 1;
            break;
        }
    }
    if(!exists) cout << -1 << nl;
    return 0;
}
