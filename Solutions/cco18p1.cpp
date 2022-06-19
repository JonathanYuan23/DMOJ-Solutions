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

ll n, dp[MAX][MAX], pGeese[MAX], pHawks[MAX];
bool geese[MAX], hawks[MAX];
string played;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL);  cout.tie(NULL);
    cin >> n >> played;
    for(int i=0; i<n; i++){
        geese[i + 1] = (played[i] == 'W') ? 1 : 0;
        cin >> pGeese[i+1];
    }
    cin >> played;
    for(int i=0; i<n; i++){
        hawks[i + 1] = (played[i] == 'W') ? 1 : 0;
        cin >> pHawks[i+1];
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            dp[i][j] = max(dp[i-1][j-1], max(dp[i-1][j], dp[i][j-1]));
            if(geese[i] != hawks[j] && pGeese[i] != pHawks[j])
                if((geese[i] && pGeese[i] > pHawks[j]) || (!geese[i] && pGeese[i] < pHawks[j])) 
                    dp[i][j] = max(dp[i][j], pGeese[i] + pHawks[j] + dp[i-1][j-1]);            
        }
    }
    cout << dp[n][n] << '\n';
    
    return 0;
};
