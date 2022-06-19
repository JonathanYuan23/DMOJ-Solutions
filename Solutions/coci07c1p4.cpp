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

const int MOD = 1000000007, INF = 0x3f3f3f3f, MX = 205, IMX = INT_MAX, IMN = INT_MIN;
const long long LLMX = LONG_LONG_MAX, LLMN = LONG_LONG_MIN;
const char nl = '\n';

const int mod = 1e5;

ll n, dp[MX][MX];
string s;

int calc(char a, char b){
    if(a == '{') return (b == '}' || b == '?');
    if(a == '[') return (b == ']' || b == '?');
    if(a == '(') return (b == ')' || b == '?');
    if(a == '?') return (b == '}' || b == ']' || b == ')') ? 1 : (b == '?' ? 3 : 0);
    return 0;
}

ll rec(int l, int r){
    if(l >= r) return 1;
    if(dp[l][r] != -1) return dp[l][r];
    ll &ret = dp[l][r]; ret = 0;
    for(int m=l+1; m<=r; m+=2){
        int coefficient = calc(s[l], s[m]);
        ret += rec(l+1, m-1) * rec(m+1, r) * coefficient;
        if(ret >= mod) ret = ret % mod + mod;
    }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL);  cout.tie(NULL);
    cin >> n >> s;
    memset(dp, -1, sizeof dp);
    ll ans = rec(0, n-1);
    if(ans >= mod) cout << setw(5) << setfill('0') << ans % mod << nl;
    else cout << ans << nl;
    return 0;
}
