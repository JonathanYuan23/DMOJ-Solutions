#include <bits/stdc++.h>
using namespace std;

int r, c, cx, cy, wx, wy, dp[50][50];
char grid[50][50];

bool solve(){

  queue<pair<int, int>> bfs;
  bfs.push({cx, cy});
  dp[cx][cy]=0;

  while(!bfs.empty()){

    int i = bfs.front().first, j = bfs.front().second;
    bfs.pop();

    if(grid[i][j]=='W')
      return true;

    if(i>0 && grid[i-1][j]!='X' && dp[i-1][j]==-1){

      dp[i-1][j] = dp[i][j]+1;

      bfs.push({i-1, j});

    }

    if(i<r-1 && grid[i+1][j]!='X' && dp[i+1][j]==-1){

      dp[i+1][j] = dp[i][j]+1;

      bfs.push({i+1, j});

    }

    if(j>0 && grid[i][j-1]!='X' && dp[i][j-1]==-1){

      dp[i][j-1] = dp[i][j]+1;

      bfs.push({i, j-1});

    }

    if(j<c-1 && grid[i][j+1]!='X' && dp[i][j+1]==-1){

      dp[i][j+1] = dp[i][j]+1;

      bfs.push({i, j+1});

    }

  }

  return false;
}

int main()
{

  int t;  cin >> t;

  while(t--){

    memset(dp, -1, sizeof dp);

    cin >> c >> r;

    for(int i{0}; i<r; i++){
      for(int j{0}; j<c; j++){

        cin >> grid[i][j];

        if(grid[i][j]=='C'){cx=i; cy=j;}
        if(grid[i][j]=='W'){wx=i; wy=j;}

      }
    }

    bool pee = solve();

    if(pee){

      if(dp[wx][wy]==-1 || dp[wx][wy]>=60)
        cout << "#notworth\n";
      else
        cout << dp[wx][wy] << "\n";

    }

    else 
      cout << "#notworth\n";

  }

  return 0;
}
