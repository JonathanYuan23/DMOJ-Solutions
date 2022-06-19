#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize "Ofast"
#define frein freopen("input.txt", "r", stdin)
#define freout freopen("output.txt", "w", stdout)
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define nl '\n'
#define fi first
#define se second
#define INF 0x3f3f3f3f
#define MAX 10005
#define IMX INT_MAX
#define IMN INT_MIN
#define LLMX LONG_LONG_MAX
#define LLMN LONG_LONG_MIN
#define pb push_back
#define pf push_front
#define LSB(x) (x & (-x))
#define sz(x) (ll)(x.size())
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<pii, pii> piiii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<piii> viii;
typedef vector<piiii> viiii;

// min ops to convert prefix of a to prefix of b
int n, m, dp[2][MAX], cur = 0, last = 1;
string a, b;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL);  cout.tie(NULL);
    cin >> n >> m >> a >> b;
    for(int i=0; i<=n; i++){
        for(int j=0; j<=m; j++){
            if(!i) dp[cur][j] = j;
            else if(!j) dp[cur][j] = i;
            else if(a[i-1] == b[j-1]) dp[cur][j] = dp[last][j-1];
            else dp[cur][j] = 1 + min(dp[cur][j-1], min(dp[last][j], dp[last][j-1]));
        }
        last = cur;
        cur ^= 1;
    }
    int ans = 0;
    for(int i=1; i<m; i++) ans += dp[last][i];
    cout << ans << nl;
    
    return 0;
};
