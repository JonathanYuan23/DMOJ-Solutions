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

const int MOD = 1000000007, INF = 0x3f3f3f3f, MX = 1e5+5, IMX = INT_MAX, IMN = INT_MIN;
const long long LLMX = LONG_LONG_MAX, LLMN = LONG_LONG_MIN;
const char nl = '\n';

int n;
vector<tuple<ll, ll, ll>> arr;
ll st, fn, hp, dp[MX];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL);  cout.tie(NULL); 
    cin >> n; arr.pb({0, 0, 0});
    for(int i=1; i<=n; i++){
        cin >> st >> fn >> hp;
        arr.pb({st+fn, st, hp});
    }
    sort(arr.begin(), arr.end());
    for(int i=1; i<=n; i++){
        st = get<1>(arr[i]), hp = get<2>(arr[i]);
        int pos = upper_bound(arr.begin(), arr.end(), make_tuple(st, LLMX,  LLMX)) - arr.begin() - 1;
        dp[i] = max(dp[i-1], hp + dp[pos]);
    }
    cout << dp[n] << nl;
    return 0;
}
