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
#define MAX 2005
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

ll n, b, l, d, B[55], L[55], D[55], dp[MAX][3];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL);  cout.tie(NULL);
    cin >> n >> b >> l >> d;
    for(int i=0; i<b; i++){
        cin >> B[i];
        dp[B[i]][0] = 1;
    }
    for(int i=0; i<l; i++) cin >> L[i];
    for(int i=0; i<d; i++) cin >> D[i];
    for(int i=1; i<=n; i++){
        for(int j=0; j<b; j++) if(i - B[j] >= 0) dp[i][0] = (dp[i][0] + dp[i - B[j]][2]) % MOD;
        for(int j=0; j<l; j++) if(i - L[j] >= 0) dp[i][1] = (dp[i][1] + dp[i - L[j]][0]) % MOD;
        for(int j=0; j<d; j++) if(i - D[j] >= 0) dp[i][2] = (dp[i][2] + dp[i - D[j]][1]) % MOD;
    }
    int ans = 0;
    for(int i=0; i<=n; i++) if(dp[i][0] + dp[i][1] + dp[i][2] > 0) ans = i;
    cout << ((dp[ans][0] + dp[ans][1]) % MOD + dp[ans][2]) % MOD << ' ' << n - ans << '\n';

    return 0;
};
