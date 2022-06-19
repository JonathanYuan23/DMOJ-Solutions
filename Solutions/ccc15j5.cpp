#include <bits/stdc++.h>
using namespace std;
const int MAXN = 251;

int dp[MAXN][MAXN][MAXN], n, k;

int solve(int person, int pies_served, int prev){

  if(person==k && pies_served==n)
    return 1;

  if((pies_served==n && person<k) || (person==k && pies_served!=n))
    return 0;
  
  if(dp[person][pies_served][prev]!=-1)
    return dp[person][pies_served][prev];

  int ans = 0;
  for(int i{prev};  i<=n-pies_served; i++){

    ans += solve(person+1, pies_served+i, i);

  }

  return dp[person][pies_served][prev] = ans;
}

int main()
{

  ios_base::sync_with_stdio(0); cin.tie(NULL);  cout.tie(NULL);

  cin >> n >> k;

  memset(dp, -1, sizeof dp);

  if(n==k || k==1)  cout << 1 << "\n";
  else  cout << solve(0, 0, 1) << "\n";

  
  return 0;
}
