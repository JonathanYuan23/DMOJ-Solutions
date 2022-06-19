#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
#define INF 0x3f3f3f3f
using namespace std;
const int MAXN = 405;

ll dp[MAXN][MAXN], prefixs[MAXN], arr[MAXN], N;

ll partials(int l, int r){

  if(l==0)  return prefixs[r];
  else  return prefixs[r] - prefixs[l-1];

}

ll solve(int l, int r){

  if(l==r)  return 0;
  
  if(dp[l][r]!=-1)  return dp[l][r];

  ll ans = LLONG_MAX;

  for(int i=l; i<r; i++){

    ll temp = partials(l, r) + solve(l, i) + solve(i+1, r);
    ans = min(ans, temp);

  }

  return dp[l][r] = ans;
}

int main(){

  ios_base::sync_with_stdio(false); cin.tie(NULL);  cout.tie(NULL);

  cin >> N;

  for(int i=0; i<N; i++)
    cin >> arr[i];

  prefixs[0] = arr[0];

  for(int i=1; i<N; i++)
    prefixs[i] = prefixs[i-1] + arr[i];

  memset(dp, -1, sizeof dp);

  cout << solve(0, N-1) << "\n";  
  
  return 0;
}
