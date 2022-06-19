#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
#define INF 0x3f3f3f3f
using namespace std;
const int MAXN = 150010;

int arr[3][MAXN], dp[3][MAXN], order[6][3] = {{0, 1, 2}, {0, 2, 1}, {1, 0, 2}, {1, 2, 0}, {2, 0, 1}, {2, 1, 0}}, N, indx;

int solve(int i, int j){

  if(i>2){

    if(j>=N)  return 0;

    return INF;

  }

  else if(j>=N)  return INF;

  if(dp[i][j]!=-1)  return dp[i][j];

  int ans = min(arr[order[indx][i]][j]+solve(i, j+1), arr[order[indx][i]][j]+solve(i+1, j+1));

  return dp[i][j] = ans;
}

int main(){

	ios_base::sync_with_stdio(false); cin.tie(NULL);  cout.tie(NULL);

  cin >> N;

  for(int i=0; i<3; i++)
    for(int j=0; j<N; j++)
      cin >> arr[i][j];

  int ans = INF;

  for(int i=0; i<6; i++){

    memset(dp, -1, sizeof dp);

    indx=i;
    ans = min(ans, solve(0, 0));

  }
  
  cout << ans << "\n";
  
  return 0;
}
