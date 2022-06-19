#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;
const int MAXN = 2001;

int N, M, dp_stress_free[MAXN][MAXN], dp_stressed[MAXN][MAXN];

int free(int n, int m){

  if(n==N && m==M)  
    return 1;
  if(n<=m)  
    return 0;
  if(n>N || m>M)  
    return 0;

  if(dp_stress_free[n][m]!=-1)
    return dp_stress_free[n][m];

  int ans = (free(n+1, m) + free(n, m+1))%MOD;

  return dp_stress_free[n][m] = ans;
}

int stressed(int n, int m){

  if(m==M) 
    return 1;
  if(n>m) 
    return 0;
  if(n>N || m>M) 
    return 0;

  if(dp_stressed[n][m]!=-1)
    return dp_stressed[n][m];

  int ans = (stressed(n+1, m) + stressed(n, m+1))%MOD;

  return dp_stressed[n][m] = ans;
}

int main(){

	ios_base::sync_with_stdio(false); cin.tie(NULL);  cout.tie(NULL);

  int t;  cin >> t;

  for(int i=1; i<=t; i++){

    memset(dp_stress_free, -1, sizeof dp_stress_free);
    memset(dp_stressed, -1, sizeof dp_stressed);

    char c; cin >> N >> c >> M;

    cout << "Case #" << i << ": " << free(1, 0) << " " << stressed(0, 0) << "\n";

  }
  
  return 0;
}
