#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
#define INF 1<<25
using namespace std;
const int MAXN = 3010;

//dp[i][j] - number of ways to make permutation of size i that ends with j
int dp[MAXN][MAXN], N; string s;

int main(){

	ios_base::sync_with_stdio(false); cin.tie(NULL);  cout.tie(NULL);

  cin >> N >> s;

  //permutation of size 1 can only end with 1, therefore this is the only option
  dp[1][1] = 1;

  //iterate through all lengths of permutations from 2 to N
  for(int i=2; i<=N; i++){

    //compute PSA for previous row (current length of permutation-1), so 1 to i-1
    for(int j=1; j<=i-1; j++)
      dp[i-1][j] = (dp[i-1][j] + dp[i-1][j-1])%MOD;

    for(int j=1; j<=i; j++){

      int left_bound, right_bound;

      if(s[i-2]=='<'){

        //get the partial prefix sum for all in previous that are < j

        left_bound = 1; right_bound = j-1;

      }
      else{

        //get the partial prefix sum for all in previous that are >= j
        left_bound = j; right_bound = i-1;

      }

      //dp[i][j] = d[i-1][range that previous j could be]
      if(right_bound-left_bound>=0)
        dp[i][j] = (dp[i][j]+(dp[i-1][right_bound]-dp[i-1][left_bound-1])+MOD)%MOD;

    }
  }

  int ans=0;
  for(int i=1; i<=N; i++) ans = (ans+dp[N][i])%MOD;

  cout << ans << "\n";
  
  return 0;
}
