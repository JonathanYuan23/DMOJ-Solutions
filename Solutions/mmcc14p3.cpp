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

const int MOD = 1e9+7, INF = 0x3f3f3f3f, MX = 5005, IMX = INT_MAX, IMN = INT_MIN;
const long long LLMX = LONG_LONG_MAX, LLMN = LONG_LONG_MIN;
const char nl = '\n';

int n, s, depth[MX], parent[MX], vis[MX];
vi adj[MX]; vii order;

void dfs(int u, int par) {
    parent[u] = par; 
    order.eb(depth[u], u);
    for(auto v: adj[u]) {
        if(v == par) continue;
        depth[v] = depth[u] + 1;
        dfs(v, u);
    }
}

void reach(int u, int par, int dist) {
    vis[u] = 1;
    if(!dist) return;
    for(auto v: adj[u]) {
        if(v == par) continue;
        reach(v, u, dist-1);
    }
}

bool ok(int dist) {
    ms(vis, 0);
    int cnt = 0;
    for(auto node: order) {
        int u = node.se;
        if(vis[u]) continue;
        for(int i=0; i<dist; i++) u = parent[u];
        cnt++;
        reach(u, -1, dist);
    }
    return cnt <= s;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);  cout.tie(0);
    cin >> n >> s;
    for(int i=0, u, v; i<n-1; i++) {
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }   
    if(s >= n) {
        cout << 0 << nl;
        return 0;
    }
    dfs(1, 1);
    sort(order.rbegin(), order.rend());
    int lo = 1, high = n-1, ans = n-1;
    while(lo <= high) {
        int mid = (lo + high) / 2;
        if(ok(mid)) {
            ans = mid;
            high = mid - 1;
        }
        else lo = mid + 1;
    }
    cout << ans << nl;
    return 0;
}
