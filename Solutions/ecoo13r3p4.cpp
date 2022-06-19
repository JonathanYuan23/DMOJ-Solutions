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

// prefix of cards, streak count, wrong or not
int n, dp[MAX][15][2], cards[MAX];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL);  cout.tie(NULL);
    for(int tc=0; tc<10; tc++){
        cin >> n;
        for(int i=1; i <= 2 * n; i++) cin >> cards[i];
        memset(dp, IMN, sizeof dp);
        dp[1][1][0] = cards[1];
        dp[1][1][1] = -1;
        for(int i=2; i <= 2 * n; i++){
            int p1, p2;
            if(i % 2 == 1){
                // current q is start of new streak, or current q is wrong and last was also wrong
                for(int j=1; j<=10; j++){
                    p1 = dp[i-1][j][1], p2 = dp[i-2][j][1];
                    if(p1 > IMN){
                        dp[i][1][0] = max(dp[i][1][0], p1 + cards[i]);
                        dp[i][1][1] = max(dp[i][1][1], p1 - 1);
                    }
                    if(p2 > IMN){
                        dp[i][1][0] = max(dp[i][1][0], p2 + cards[i]);
                        dp[i][1][1] = max(dp[i][1][1], p2 - 1);
                    }
                }
            }
            // continuation of streak, iterate over current level of streak
            for(int j=2; j<=9; j++){
                p1 = dp[i-1][j-1][0];
                if(p1 > IMN) dp[i][j][0] = max(dp[i][j][0], p1 + cards[i]);
            }
            // loses current q, previous q was right
            for(int j=2; j<=10; j++){
                p1 = dp[i-1][j-1][0];
                if(p1 > IMN) dp[i][j][1] = max(dp[i][j][1], p1 - 1);
            }
        }
        int ans = 0;
        for(int i=0; i<=10; i++) ans = max(ans, max(dp[n * 2][i][0], dp[n * 2][i][1]));
        cout << ans << nl;
    }
    
    return 0;
};
