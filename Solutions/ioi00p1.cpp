#include <bits/stdc++.h>
#define MOD 1000000007
#define ll long long
using namespace std;
const int MAXN = 5010;

int dp[3][MAXN];

int main()
{
    
  ios_base::sync_with_stdio(0); cin.tie(NULL);  cout.tie(NULL);

  int n;  string s;
  cin >> n >> s;

  for(int i=0; i<n; i++)
    dp[0][i] = dp[1][i] = 0;

  for(int i=2; i<=n; i++){

    for(int j=0; j<n; j++)  dp[2][j] = INT_MAX;

    for(int j=0; j+i-1<n; j++){

      if(s[j] == s[j + i - 1])  dp[2][j] = dp[0][j+1];

      else  dp[2][j] = min(dp[1][j+1], dp[1][j]) + 1;

    }

    swap(dp[0], dp[1]); swap(dp[1], dp[2]);

  }

  cout << dp[1][0] << "\n";
   
  return 0;
}
