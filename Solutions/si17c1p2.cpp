#include <bits/stdc++.h>
#define MOD 1000000007
#define ll long long
using namespace std;
const int MAXN = 100010;

long long dp[MAXN], fish[MAXN], N, K;

long long solve(int i){

  if(i>=N)
    return 0;

  if(dp[i]!=-1)
    return dp[i];

  dp[i] = max(fish[i] + solve(i+K+1), solve(i+1));

  return dp[i];
}

int main()
{
    
  ios_base::sync_with_stdio(0); cin.tie(NULL);  cout.tie(NULL);
  memset(dp, -1, sizeof dp);

  cin >> N >> K;

  for(int i=0; i<N; i++)
    cin >> fish[i];

  cout << solve(0) << "\n";
   
  return 0;
}
