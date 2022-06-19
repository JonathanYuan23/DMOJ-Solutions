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

const int MOD = 1e9+7, INF = 0x3f3f3f3f, MX = 200005, IMX = INT_MAX, IMN = INT_MIN;
const long long LLMX = LONG_LONG_MAX, LLMN = LONG_LONG_MIN;
const char nl = '\n';

int N, R, X, Y, ans = IMX, path[MX], vis[MX], dis[MX];
vi adj[MX];
queue<int> q;

bool prune(int u, int p) {
    for(auto v: adj[u]) {
        if(v != p) {
            path[u] |= prune(v, u);
        }
    }
    return path[u];
}

void bfs() {
    while(!q.empty()) {
        int u = q.front(); q.pop();
        for(auto v: adj[u]) {
            if(!vis[v]) {
                dis[v] = dis[u] + 1, vis[v] = 1;
                q.push(v);
            }
        }
    }
}

void dfs(int u, int p) {
    ans = min(ans, dis[u]);
    for(auto v: adj[u]) {
        if(v != p && path[v]) {
            dfs(v, u);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);  cout.tie(0);
    cin >> N >> R;
    for(int i=0, u, v; i<N-1; i++) {
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    for(int i=0, r; i<R; i++) {
        cin >> r;
        vis[r] = 1;
        q.push(r);
    }
    cin >> X >> Y; path[Y] = 1;
    prune(X, -1); bfs(); dfs(X, -1);
    cout << ans << nl;
    return 0;
}
