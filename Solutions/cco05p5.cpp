#include <bits/stdc++.h>
#define l first
#define r second
using namespace std;

int n;  vector<pair<int, int>> segments;

unordered_map<string, int> dp;

int solve(int i, int j){

  string key = to_string(i) + "|" + to_string(j);

  if(dp[key])
    return dp[key];

  if(i==1 && i!=n)
    dp[key] = segments[i-1].r + solve(i+1, segments[i-1].r);

  else if(i==n){

    if((j>=segments[i-1].l && j<=segments[i-1].r) || j>=segments[i-1].r)
      dp[key] = (j-segments[i-1].l) + (n-segments[i-1].l);

    else if(j<=segments[i-1].l)
      dp[key] = n-j;

  }

  else{

    if(j>=segments[i-1].l && j<=segments[i-1].r)
      dp[key] = min((1+j-segments[i-1].l)+(segments[i-1].r-segments[i-1].l)+solve(i+1, segments[i-1].r), (1+segments[i-1].r-j)+(segments[i-1].r-segments[i-1].l)+solve(i+1, segments[i-1].l));

    else if(j>=segments[i-1].r)
      dp[key] = (1+j-segments[i-1].l)+solve(i+1, segments[i-1].l);

    else if(j<=segments[i-1].l)
      dp[key] = (1+segments[i-1].r-j)+solve(i+1, segments[i-1].r);

  }
  
  return dp[key];
}

int main()
{
    
  ios_base::sync_with_stdio(0); cin.tie(NULL);  cout.tie(NULL);

  int l, r;  cin >> n;

  for(int i{0}; i<n; i++){

    cin >> l >> r;
    segments.push_back({l, r});

  }
  
  cout << solve(1, 1) << "\n";
  
  return 0;
}
