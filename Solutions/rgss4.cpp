#include <bits/stdc++.h>
using namespace std;

int dp[1000], shirts[1000], n;

int solve(){

  for(int i{0}; i<n; i++)
    dp[i] = shirts[i];

  for(int i{1}; i<n; i++){
    for(int j{0}; j<i; j++){

      if(shirts[i]>shirts[j] && dp[i]<dp[j]+shirts[i])
        dp[i] = dp[j]+shirts[i];

    }
  }

  return *max_element(dp, dp+n);
}

int main()
{

  cin >> n;

  for(int i{0}; i<n; i++)
    cin >> shirts[i];

  memset(dp, -1, sizeof dp);
  cout << solve() << "\n";
  
  return 0;
}
