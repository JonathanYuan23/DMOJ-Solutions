#pragma GCC optimize "Ofast"
#include <bits/stdc++.h>
using namespace std; using pii = pair<int, int>;  using piii = pair<int, pii>;  using piiii = pair<pii, pii>;  using vi = vector<int>;  using vii = vector<pii>;  using viii = vector<piii>;  using viiii = vector<piiii>;
#define frein freopen("input.txt", "r", stdin)
#define freout freopen("output.txt", "w", stdout)
#define ll long long
#define ull unsigned long long
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

ll n, arr[MX], dp[MX][MX];

ll solve(int l, int r){
	if(l == r || l + 1 == r) return 0;
	if(dp[l][r] != -1) return dp[l][r];
	ll ret = -1;
	// assume arr[l], arr[i], arr[r] is the final triplet, the only way arr[i] can exist as a middle integer is if it 
	// was never used before, meaning that it was a arr[l] or arr[r] value of a smaller range
	for(int i = l + 1; i < r; i++) ret = max(ret, solve(l, i) + solve(i, r) + arr[l] + arr[i] + arr[r]);
	return dp[l][r] = ret;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL);  cout.tie(NULL);
    cin >> n;
	while(n){
		for(int i=1; i<=n; i++) cin >> arr[i];
		memset(dp, -1, sizeof dp);
		cout << solve(1, n) << nl;
		cin >> n;
	}
    return 0;
}
