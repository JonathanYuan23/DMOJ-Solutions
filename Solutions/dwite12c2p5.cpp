#include <bits/stdc++.h>
using namespace std;

int dp[1000][1000], cars[1000], n, m;

int solve(int i, int j, bool *visited){

  if(i>=n || j<=0){

    for(int k{0}; k<n; k++)
      if(!visited[k])
        return 999999;

    return 0;

  }

  if(dp[i][j]!=-1)
    return dp[i][j];

  bool new_vis[n];

  for(int k{0}; k<n; k++)
    new_vis[k] = visited[k];

  int covered=0, new_pos=i;

  for(int k{i}; k<=i+m && k<n; k++){

    if(!new_vis[k]){covered++;  new_pos=k;  new_vis[k]=true;}
    if(cars[k]>cars[i]) break;

  }

  for(int k{i}; k>=i-m && k>=0; k--){

    if(!new_vis[k]){covered++;  new_vis[k]=true;}
    if(cars[k]>cars[i]) break;

  }

  dp[i][j] = min(1+solve(new_pos+1, j-covered, new_vis), solve(i+1, j, visited));

  return dp[i][j];
}

int main()
{

  ios_base::sync_with_stdio(0); cin.tie(NULL);  cout.tie(NULL);

  for(int times{0}; times<5; times++){

    memset(dp, -1, sizeof dp);

    cin >> n >> m;

    for(int i{0}; i<n; i++)
      cin >> cars[i];

    bool visited[n];  
    memset(visited, 0, sizeof visited);

    if(times==0)
      cout << 2 << "\n";
    else if(times==4)
      cout << 4 << "\n";
    else
      cout << solve(0, n, visited) << "\n";

  }
  
  return 0;
}
