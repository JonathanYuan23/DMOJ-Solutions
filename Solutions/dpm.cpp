#include <bits/stdc++.h>
#define MOD 1000000007
#define ll long long
using namespace std;
const int MAXN = 100010;

int candies[101], dp[101][MAXN], N, K;

int main()
{
    
  ios_base::sync_with_stdio(0); cin.tie(NULL);  cout.tie(NULL);

  cin >> N >> K;

  for(int i=1; i<=N; i++)
    cin >> candies[i];

  dp[0][0] = 1;

  for(int i=1; i<=K; i++)
    dp[0][i] = 0;

  for(int i=1; i<=N; i++){

    for(int j=1; j<=K; j++){

      dp[i-1][j] = (dp[i-1][j] + dp[i-1][j-1])%MOD;

    }

    for(int j=0; j<=K; j++){

      dp[i][j] = dp[i-1][j];

      int exclude = j-candies[i]-1;

      if(exclude>=0) 
        dp[i][j] = (dp[i][j] - dp[i-1][exclude]+MOD)%MOD;

    }

  }

  cout << dp[N][K] << "\n";
   
  return 0;
}
