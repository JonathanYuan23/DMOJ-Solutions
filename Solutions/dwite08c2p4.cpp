#include<bits/stdc++.h>
using namespace std;

int main()
{

  for(int i{0}; i<5; i++){

    int values, weights, value, weight; cin >> weights >> values;

    int r[values], s[values];


    for(int i=0; i<values; i++){

      cin >> weight >> value;

      r[i] = value; s[i] = weight;

    }

    int dp[values+1][weights+1];

    for(int i{0}; i<=values; i++){
      for(int j{0}; j<=weights; j++){

        if(i==0||j==0)
          dp[i][j]=0;

        else if(s[i-1]<=j)
          dp[i][j] = max(r[i-1]+dp[i-1][j-s[i-1]], dp[i-1][j]);

        else
          dp[i][j] = dp[i-1][j];

      }
    }

    cout << dp[values][weights] << "\n";

  }

  return 0;
}
