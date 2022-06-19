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
#define MAX 1005
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
pii problems[MAX];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);  cout.tie(NULL);
    cin >> n >> m;
    // v h
    for(int i=1; i<=n; i++) cin >> problems[i].fi >> problems[i].se;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            dp[cur][j] = dp[last][j];
            if(j - problems[i].se >= 0) dp[cur][j] = max(dp[cur][j], dp[last][j - problems[i].se] + problems[i].fi);
        }
        last = cur; cur ^= 1;
    }
    cout << dp[last][m] << nl;

    return 0;
};
