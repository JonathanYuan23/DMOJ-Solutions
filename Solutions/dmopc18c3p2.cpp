#include <bits/stdc++.h>
using namespace std;

int dp[100000][3];

int n;

long long solve(int i, int k, int *french, int *english){

  if(i==n)
    return 0;

  if(dp[i][k]==-1){

    if(k<2){

      dp[i][k] = 
      max(french[i] + solve(i+1, k+1, french, english), english[i] +solve(i+1, 0, french, english));

    }
    else{

      dp[i][k] = english[i] + solve(i+1, 0, french, english);

    }

  }

  return dp[i][k];

}

int main()
{

  cin >> n;

  int french[n], english[n];

  for(int i=0;  i<n; i++)
    cin >> french[i];

  for(int i=0;  i<n; i++)
    cin >> english[i];

  memset(dp, -1, sizeof dp);

  cout << solve(0, 0, french, english) << "\n";

  return 0;
}
