#include <bits/stdc++.h>
#define MOD 1000000007
#define ll long long
using namespace std;
const int MAXN = 2001;

int dp[MAXN], N; set<string> dict;
string s;

int solve(){

  for(int i=0; i<=s.size(); i++)
    dp[i] = (1<<20);

  dp[0]=0;

  for(int i=0; i<s.length(); i++){

    for(int j=0; i+j<=s.length(); j++){

      if(dict.find(s.substr(i, j))!=dict.end())
        dp[i+j] = min(dp[i+j], dp[i]+1);

    }
  }

  return dp[s.size()]-1;
}

int main()
{
    
  ios_base::sync_with_stdio(0); cin.tie(NULL);  cout.tie(NULL);

  cin >> N;
  for(int i=0; i<N; i++){

    cin >> s; dict.insert(s);

  }

  for(int i=0; i<10; i++){

    cin >> s;
    cout << solve() << "\n";

  }
 
  return 0;
}
