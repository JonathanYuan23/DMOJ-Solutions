#include<bits/stdc++.h>
using namespace std;

int dp[1500][1500]; long long arr[1500][1500];

int n;
int solve(int i, int j, int move){

  if(dp[i][j]!=-1)
    return dp[i][j];

  if(i>0 && arr[i-1][j] > arr[i][j])
    dp[i][j] = max(dp[i][j], 1 + solve(i-1, j, move+1));

  if(i<n-1 && arr[i+1][j] > arr[i][j])
    dp[i][j] = max(dp[i][j], 1 + solve(i+1, j, move+1));

  if(j>0 && arr[i][j-1] > arr[i][j])
    dp[i][j] = max(dp[i][j], 1 + solve(i, j-1, move+1));
  
  if(j<n-1 && arr[i][j+1] > arr[i][j])
    dp[i][j] = max(dp[i][j], 1 + solve(i, j+1, move+1));

  return dp[i][j];
}
  
int main()
{  
  cin >> n;

  for(int i{0}; i<n; i++)
    for(int j{0}; j<n; j++)
      cin >> arr[i][j];

  memset(dp, -1, sizeof dp);

  int mx = INT_MIN;
  for(int i{0}; i<n; i++){
    for(int j{0}; j<n; j++){
      if(dp[i][j]==-1)
        solve(i, j, 0);

      mx = max(mx, dp[i][j]);

    }
  }

  cout << mx+1 << "\n";

  return 0;
}
