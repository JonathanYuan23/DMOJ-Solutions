#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize "Ofast"
#define frein freopen("input.txt", "r", stdin)
#define freout freopen("output.txt", "w", stdout)
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define fi first
#define se second
#define INF 0x3f3f3f3f3f3f3f3f
#define MAX 1005
#define pb push_back
#define LSB(S) (S & (-S))
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<pii, pii> piiii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<piii> viii;
typedef vector<piiii> viiii;

// current teacher, amount of time left
int dp[55][MAX], ttime[55][MAX], h[55], e[55], p[55], s, n;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL);  cout.tie(NULL);

    cin >> n;

    for(int i=1; i<=n; i++) cin >> h[i] >> e[i] >> p[i];

    cin >> s;

    for(int i=1; i<=n; i++){

        for(int j=0; j<=s; j++){

            dp[i][j] = dp[i-1][j];

            ttime[i][j] = ttime[i-1][j];

            int curTeach = 0;

            for(int k=0; h[i]-k*e[i]>0 && j+(k+1)*p[i]<=s; k++){

                curTeach += h[i]-k*e[i];

                if(curTeach + dp[i-1][j + (k+1) * p[i]] > dp[i][j]){

                    dp[i][j] = curTeach + dp[i-1][j + (k+1) * p[i]];

                    ttime[i][j] = k + 1 + ttime[i-1][j + (k+1) * p[i]];

                }

                else if(curTeach + dp[i-1][j + (k+1) * p[i]] == dp[i][j]) ttime[i][j] = min(ttime[i][j], k + 1 + ttime[i-1][j + (k+1) * p[i]]);

            }

        }

    }

    int ans = INT_MIN, atime;

    for(int i=0; i<=s; i++){

        if(dp[n][i] > ans){

            ans = dp[n][i];

            atime = ttime[n][i];

        }

        else if(dp[n][i] == ans){

            atime = min(atime, ttime[n][i]);

        }

    }

    cout << ans << '\n' << atime << '\n';

    return 0;
}
