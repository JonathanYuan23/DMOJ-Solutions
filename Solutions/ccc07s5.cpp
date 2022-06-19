#pragma GCC optimize "Ofast"
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MOD 1000000009
#define fi first
#define se second
#define INF 0x3f3f3f3f
#define MAXN 30005
#define pb push_back
#define LSB(S) (S & (-S))
typedef pair<int, int> pii;
typedef pair<pair<int, int>, int> piii;

int dp[MAXN][505], pins[MAXN], psa[MAXN];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL);  cout.tie(NULL);
    int t, n, k, w;
    cin >> t;
    while(t--){
        cin >> n >> k >> w;
        for(int i=1; i<=n; i++){
            cin >> pins[i];
            psa[i]=pins[i] + ((i==0)?0:psa[i-1]);
        }
        int sum;
        for(int i=w; i<=n; i++){
            for(int j=0; j<=k; j++){
                if(i==0||j==0){
                    dp[i][j]=0;
                    continue;
                }
                dp[i][j] = max(dp[i-1][j], dp[i-w][j-1] + (psa[i]-psa[i-w]));
            }
        }
        cout << dp[n][k] << "\n";
    }
    
    return 0;
}
