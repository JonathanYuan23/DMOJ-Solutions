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
#define MAX 5005
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

ll n, m, cur = 1, last = 0, dp[2][MAX];
pair<ll, pair<ll, ll>> items[MAX];
pair<ll, ll> trucks[MAX];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);  cout.tie(NULL);
    cin >> n >> m;
    // n v p
    for(int i=1; i<=n; i++) cin >> items[i].fi >> items[i].se.fi >> items[i].se.se;
    for(int i=1; i<=m; i++) cin >> trucks[i].fi >> trucks[i].se;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=5000; j++){
            dp[cur][j] = dp[last][j];
            for(int k=1; k<=items[i].fi && j - (items[i].se.fi * k) >= 0; k++) 
                dp[cur][j] = max(dp[cur][j], dp[last][j - (items[i].se.fi * k)] + (items[i].se.se * k));
        }
        last = cur; cur ^= 1;
    }
    ll ans = LLMN;
    for(int i=1; i<=m; i++) ans = max(ans, dp[last][trucks[i].fi] - trucks[i].se);
    cout << ans << nl;

    return 0;
};
