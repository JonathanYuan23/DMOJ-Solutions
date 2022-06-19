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

const int MOD = 1000000007, INF = 0x3f3f3f3f, MX = 3005, IMX = INT_MAX, IMN = INT_MIN;
const long long LLMX = LONG_LONG_MAX, LLMN = LONG_LONG_MIN;
const char nl = '\n';

ll n, psa[MX], dp[MX][MX];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL);  cout.tie(NULL);
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> dp[i][i];
        psa[i] = psa[i-1] + dp[i][i];
    }
    for(int len = 2; len <= n; len++){
        for(int l = 1, r; l + (len - 1) <= n; l++){
            r = l + (len - 1);
            dp[l][r] = (psa[r] - psa[l-1]) - min(dp[l+1][r], dp[l][r-1]);
        }   
    }
    cout << dp[1][n] - (psa[n] - dp[1][n]) << nl;
    
    return 0;
}
