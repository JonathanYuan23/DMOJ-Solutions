#include<bits/stdc++.h>
using namespace std;

int main()
{

  string s, t;  cin >> s >> t;

  int dp[s.size()+1][t.size()+1];

  for(int i{0}; i<=s.size();  i++){
    for(int j{0}; j<=t.size();  j++){

      if(i==0 || j==0)
        dp[i][j]=0;

      else{

        dp[i][j] = max(dp[i][j-1], dp[i-1][j]);

        if(s[i-1]==t[j-1])
          dp[i][j] = max(dp[i][j], dp[i-1][j-1]+1);

      }

    }
  }

  string res = "";

  int i=s.size(), j=t.size();

  while(i>0 && j>0){

    if(s[i-1]==t[j-1]){

      res+=s[i-1];
      i--;
      j--;

    }
    else{

      if(dp[i-1][j]>dp[i][j-1])
        i--;
      
      else
        j--;
    }

  }

  reverse(res.begin(), res.end());

  cout << res << "\n";

  return 0;
}
