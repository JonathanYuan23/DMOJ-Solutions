#include<bits/stdc++.h>
using namespace std;

int main()
{

  int m, n; 

  for(int i{0}; i<5; i++){

    cin >> m; vector<int> dp(m+1, m+1);
    cin >> n; vector<int> vals(n);

    for(int i{0}; i<n; i++)
      cin >> vals[i];

    dp[0] = 0;

    for(int i{1}; i<=m; i++){
      for(int j{0}; j<n; j++){

        if(vals[j]<=i){

          dp[i] = min(dp[i], dp[i-vals[j]]+1);

        }

      }
    }

    cout << dp[m] << "\n";

  }

  return 0;
}
