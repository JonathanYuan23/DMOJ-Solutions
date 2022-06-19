#include <bits/stdc++.h>
using namespace std;

int dp[101][101][101], N, T; vector<pair<int, int>> knapsack[100];

int solve(int i, int j, int time_left){

  if(i==0 || time_left<=0)
    return 0;

  if(j==knapsack[i-1].size() || knapsack[i-1][j].first>time_left)
    return solve(i-1, 0, time_left);

  if(dp[i][j][time_left]!=-1)
    return dp[i][j][time_left];

  int ans = 
  max(knapsack[i-1][j].second+solve(i, j+1, time_left-knapsack[i-1][j].first), knapsack[i-1][j].second+solve(i-1, 0, time_left-knapsack[i-1][j].first));

  ans = max(ans, solve(i-1, 0, time_left));

  return dp[i][j][time_left] = ans;
}

int main()
{
    
  ios_base::sync_with_stdio(0); cin.tie(NULL);  cout.tie(NULL);
  memset(dp, -1, sizeof dp);

  cin >> N >> T;

  for(int i{0}; i<N; i++){

    int l, times, val;  cin >> l;

    for(int j{0}; j<l; j++){cin >> times >> val;  knapsack[i].push_back({times, val});}

  }

  cout << solve(N, 0, T) << "\n";
  
  return 0;
}
