#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
#define INF 1<<30
using namespace std;
const int MAXN = 65;

ll N, dp[MAXN];

ll combi(int n){

  if(dp[n]!=-1) return dp[n];

  if(n==0 || n==1) return 1;

  ll count=1;

  for(int i=n-2; i>=0; i-=2) count += combi(i);

  return dp[n] = count;
}

int main(){

	ios_base::sync_with_stdio(0); cin.tie(NULL);  cout.tie(NULL);
  
  cin >> N;

  memset(dp, -1, sizeof dp);
  cout << combi(N) << "\n";
  

  return 0;
}
