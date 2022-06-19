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
#define LSB(x) (x & (-x))
#define sz(x) (int)(x.size())
#define ms(a, b) memset(a, b, sizeof a)

const int MOD = 1000000007, INF = 0x3f3f3f3f, MX = 100005, IMX = INT_MAX, IMN = INT_MIN;
const long long LLMX = LONG_LONG_MAX, LLMN = LONG_LONG_MIN;
const char nl = '\n';

int n, k, dp[MX], a[105];

int rec(int stones){
    if(!stones) return 0;
    if(dp[stones] != -1) return dp[stones];
    int ans = 0;
    for(int i=0; i<n; i++) if(stones - a[i] >= 0) ans |= !rec(stones - a[i]);
    return dp[stones] = ans;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL);  cout.tie(NULL); 
    cin >> n >> k;
    for(int i=0; i<n; i++) cin >> a[i];
    ms(dp, -1);
    cout << (rec(k) ? "First" : "Second") << nl;
    return 0;
}
