#include <bits/stdc++.h>
#define MOD 1000000007
#define ll long long
using namespace std;
const int MAXN = 1000;

int dp[MAXN]; string dict[10] = {"ook", "ookook", "oog", "ooga", "ug", "mook", "mookmook", "oogam", "oogum", "ugug"};
string s;

int solve(){

  dp[0] = 1;

  for(int i=0; i<s.size(); i++){
    for(int j=0; j<10; j++){

      if(i + dict[j].size() <= s.size() && s.substr(i, dict[j].size())==dict[j])
        dp[i + dict[j].size()] += dp[i];

    }
  }

  return dp[s.size()];
}

int main()
{
    
  ios_base::sync_with_stdio(0); cin.tie(NULL);  cout.tie(NULL);

  for(int i=0; i<10; i++){

    memset(dp, 0, sizeof dp);

    cin >> s;
    cout << solve() << "\n";

  }
 
   
  return 0;
}
