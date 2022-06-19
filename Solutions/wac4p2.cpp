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

const int MOD = 1000000007, INF = 0x3f3f3f3f, MX = 5005, IMX = INT_MAX, IMN = INT_MIN;
const long long LLMX = LONG_LONG_MAX, LLMN = LONG_LONG_MIN;
const char nl = '\n';

ll n, v, p, tot = 0, ans = LLMX, dp[MX][MX];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL);  cout.tie(NULL);
    cin >> n;
    for(int i=0; i<=n; i++) for(int j=0; j<MX; j++) if(j) dp[i][j] = LLMX;
    for(int i=1; i<=n; i++){
        cin >> v >> p; 
        tot += p;
        v = (v / 2) + 1;
        for(int j=0; j<MX; j++){
            dp[i][j] = dp[i-1][j];
            if(j - p >=0 && dp[i-1][j-p] != LLMX) dp[i][j] = min(dp[i][j], dp[i-1][j-p] + v);
        }
    }
    for(int i=(tot / 2) + 1; i<MX; i++) ans = min(ans, dp[n][i]);
    cout << ans << nl;
    
    return 0;
}
