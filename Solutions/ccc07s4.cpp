#include <bits/stdc++.h>
using namespace std;
 
int main()
{ 

  cin.sync_with_stdio(0); cin.tie(0);

  int n, x, y;  cin >> n;

  vector<int> water[n];

  cin >> x >> y;

  while(!(x==0 && y==0)){

    water[y-1].push_back(x-1);
    cin >> x >> y;

  }

  int dp[n];
  for(int i{0}; i<n; i++)
    dp[i] = 0;
    
  dp[n-1] = 1;

  for(int i{n-1}; i>=0; i--){
    for(int j{0}; j<water[i].size(); j++){
      dp[water[i][j]] += dp[i];
    }
  }

  cout << dp[0] << "\n";
    
  return 0;
}
