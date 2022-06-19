#include<bits/stdc++.h>
using namespace std;

int hap[100000][3]; long long dp[100000][3];

int main()
{

  memset(dp, -1, sizeof dp);

  int n;  cin >> n;

  for(int i=0; i<n; i++)
    for(int j=0; j<3; j++)
      cin >> hap[i][j];

  dp[0][0] = hap[0][0]; dp[0][1] = hap[0][1]; dp[0][2] = hap[0][2];

  for(int i=1; i<n; i++){
    for(int j=0; j<3; j++){
      for(int k=0; k<3; k++){

        if(j^k){

          dp[i][j] = max(dp[i][j], dp[i-1][k] + hap[i][j]);

        }

      }
    }
  }

  cout << max(dp[n-1][0], max(dp[n-1][1], dp[n-1][2])) << "\n";

  return 0;
}
