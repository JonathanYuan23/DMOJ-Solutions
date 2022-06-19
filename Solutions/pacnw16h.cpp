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

const int MOD = 1000000007, INF = 0x3f3f3f3f, MX = 200005, IMX = INT_MAX, IMN = INT_MIN;
const long long LLMX = LONG_LONG_MAX, LLMN = LONG_LONG_MIN;
const char nl = '\n';

ll lim, n;
ll a, b, dp[MX], cmax[MX]; vector<pair<ll, ll>> painters;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL);  cout.tie(NULL); 
    cin >> lim >> n;
    for(int i=1; i<=n; i++){
        cin >> a >> b; painters.emplace_back(b, a);
    }
    painters.emplace_back(0, 0);
    sort(painters.begin(), painters.end());
    for(int i=1; i<sz(painters); i++){
        a = painters[i].se, b = painters[i].fi; 
        int pos = upper_bound(painters.begin(), painters.end(), make_pair(a - 1, LLMX)) - painters.begin() - 1;
        dp[i] = max(dp[i - 1], dp[pos] + (b - a + 1));
    }
    cout << lim - dp[sz(painters)-1] << nl;
    return 0;
}
