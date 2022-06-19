#pragma GCC optimize "Ofast"
#include <bits/stdc++.h>
using namespace std; using pii = pair<int, int>;  using piii = pair<int, pii>;  using piiii = pair<pii, pii>;  using vi = vector<int>;  using vii = vector<pii>;  using viii = vector<piii>;  using viiii = vector<piiii>; using ll = long long; using ull = unsigned long long; 
#define frein freopen("input.txt", "r", stdin)
#define freout freopen("output.txt", "w", stdout)
// #define fi first
// #define se second
#define sum first
#define ways second
#define pb push_back
#define pf push_front
#define ppb pop_back
#define LSB(x) (x & (-x))
#define sz(x) (int)(x.size())

const int MOD = 1000000007, INF = 0x3f3f3f3f, MX = 100005, IMX = INT_MAX, IMN = INT_MIN;
const long long LLMX = LONG_LONG_MAX, LLMN = LONG_LONG_MIN;
const char nl = '\n';

int N, M, indeg[MX], outdeg[MX];
pair<ll, ll> dp[MX];
vi adj[MX];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL);  cout.tie(NULL); 
    cin >> N >> M;
    for(int i=0, u, v; i<M; i++){
        cin >> u >> v;
        adj[u].pb(v);
        indeg[v]++, outdeg[u]++;
    }
    for(int i=1; i<=N; i++) if(!outdeg[i]) dp[i].ways = 1;
    ll ans = 0;
    for(int node=N; node>=1; node--){
        for(auto &to: adj[node]){
            dp[node].ways = (dp[node].ways + dp[to].ways) % MOD;
            dp[node].sum = (dp[node].sum + dp[to].sum) % MOD;
        }
        if(outdeg[node]) dp[node].sum = (dp[node].sum + dp[node].ways) % MOD;
        if(!indeg[node]) ans = (ans + dp[node].sum) % MOD;
    }
    cout << ans << nl;
    return 0;
}
