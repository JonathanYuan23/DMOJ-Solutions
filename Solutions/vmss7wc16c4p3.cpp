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
#define umap unordered_map
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<pii, pii> piiii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<piii> viii;
typedef vector<piiii> viiii;  

int D, I, R, dp[MAX][MAX];
string a, b;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL);  cout.tie(NULL);
    cin >> D >> I >> R >> a >> b;
    for(int i=0; i<=sz(a); i++){
        for(int j=0; j<=sz(b); j++){
            if(!i) dp[i][j] = I * j;
            else if(!j) dp[i][j] = D * i;
            else if(a[i-1] == b[j-1]) dp[i][j] = dp[i-1][j-1];
            else dp[i][j] = min(dp[i][j-1] + I, min(dp[i-1][j] + D, dp[i-1][j-1] + R));
        }
    }
    cout << dp[sz(a)][sz(b)] << nl;
    return 0;
}
