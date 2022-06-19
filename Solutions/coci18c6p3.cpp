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
#define MAX 505
#define IMX INT_MAX
#define IMN INT_MIN
#define LLMX LONG_LONG_MAX
#define LLMN LONG_LONG_MIN
#define pb push_back
#define pf push_front
#define LSB(x) (x & (-x))
#define sz(x) (ll)(x.size())
#define umap unordered_map
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<pii, pii> piiii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<piii> viii;
typedef vector<piiii> viiii;  

ll n, m, K, p[MAX], b[MAX], dp[MAX][MAX];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL);  cout.tie(NULL);
    cin >> n >> m >> K;
    for(int i=1; i<=n; i++) cin >> p[i];
    for(int i=0; i<=m; i++) cin >> b[i];
    for(int i=1; i<=n; i++){
        for(int j=0; j<=K; j++){
            dp[i][j] = dp[i-1][j] + b[p[i]];
            for(int k=0; k<=j && p[i] + k <= m; k++) dp[i][j] = max(dp[i][j], dp[i-1][j - k] + b[p[i] + k]);
        }
    }
    cout << dp[n][K] << nl;
    return 0;
}
