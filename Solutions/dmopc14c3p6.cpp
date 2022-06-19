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
#define umap unordered_map
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<pii, pii> piiii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<piii> viii;
typedef vector<piiii> viiii;  

ll n, t, P[MAX][3], V[MAX][3], dp[2][MAX * 5], cur = 0, last = 1;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL);  cout.tie(NULL);
    cin >> n >> t;
    for(int i=0; i<n; i++) for(int j=0; j<3; j++) cin >> P[i][j] >> V[i][j];
    for(int i=0; i<n; i++){
        for(int j=0; j<=t; j++){
            dp[cur][j] = dp[last][j];
            for(int k=0; k<3; k++){
                if(j - P[i][k] < 0) continue;
                dp[cur][j] = max(dp[cur][j], dp[last][j - P[i][k]] + V[i][k]);
            }
        }
        last = cur;
        cur ^= 1;
    }
    cout << dp[last][t] << nl;
    
    return 0;
}
