#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
const int MAXN = 3000;

double prob[MAXN], dp[MAXN][MAXN];

int main()
{
    
  ios_base::sync_with_stdio(0); cin.tie(NULL);  cout.tie(NULL);
  fill_n(&dp[0][0], 3000*3000, 0.0);
  
  int N;  cin >> N;

  for(int i=1; i<=N; i++)
    cin >> prob[i];

  dp[1][0] = 1.0-prob[1];

  for(int i=2; i<=N; i++)
    dp[i][0] = dp[i-1][0] * (1.0-prob[i]);

  dp[1][1] = prob[1];

  for(int i=2; i<=N; i++)
    dp[i][i] = dp[i-1][i-1] * prob[i];

  for(int i=1; i<=N; i++)
    for(int j=1; j<i; j++)
      dp[i][j] = (dp[i-1][j-1] * prob[i]) + (dp[i-1][j] * (1.0-prob[i]));

  double sum=0.0;

  for(int i=N/2+1; i<=N; i++)
    sum += dp[N][i];
  
  cout << fixed << setprecision(9) << sum << "\n";
   
  return 0;
}
