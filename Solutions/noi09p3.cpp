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

const int MOD = 1000000007, INF = 0x3f3f3f3f, MX = 100, IMX = INT_MAX, IMN = INT_MIN;
const long long LLMX = LONG_LONG_MAX, LLMN = LONG_LONG_MIN;
const char nl = '\n';

ll n, k, dp[MX][MX][MX], psa[MX];
piii nodes[MX];

bool comp(piii a, piii b){
    return a.se.fi < b.se.fi;
}

ll solve(int l, int r, int w){
    if(l > r) return 0;
    if(dp[l][r][w] != -1) return dp[l][r][w];
    ll ans = IMX, sum = psa[r] - psa[l-1];
    for(int m=l; m<=r; m++){
        ans = min(ans, solve(l, m-1, w) + solve(m+1, r, w) + sum + k);
        if(nodes[m].se.fi >= w) ans = min(ans, solve(l, m-1, nodes[m].se.fi) + solve(m+1, r, nodes[m].se.fi) + sum);
    }
    return dp[l][r][w] = ans;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL);  cout.tie(NULL);
    cin >> n >> k;
    // key
    for(int i=1; i<=n; i++) cin >> nodes[i].fi;
    // priority
    for(int i=1; i<=n; i++) cin >> nodes[i].se.fi;
    // frequency
    for(int i=1; i<=n; i++) cin >> nodes[i].se.se;
    sort(nodes + 1, nodes + n + 1, comp);
    for(int i=1; i<=n; i++) nodes[i].se.fi = i;
    sort(nodes + 1, nodes + n + 1);
    for(int i=1; i<=n; i++) psa[i] = psa[i-1] + nodes[i].se.se;
    memset(dp, -1, sizeof dp);
    cout << solve(1, n, 0) << nl;
    
    return 0;
}
