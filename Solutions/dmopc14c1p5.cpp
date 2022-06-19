#include <bits/stdc++.h>
using namespace std;

int n, m, sx, sy, mx, my, tdist=INT_MAX, dp[1000][1000];

char grid[1000][1000];

void solve(){

  queue<pair<int, int>> bfs;
  bfs.push({sx, sy});
  dp[sx][sy] = 0;

  if(grid[sx][sy]=='T')
    tdist = 0;

  while(!bfs.empty()){

    int x = bfs.front().first, y = bfs.front().second;
    bfs.pop();

    if(x>0 && grid[x-1][y]!='X' && dp[x-1][y]==-1){

      dp[x-1][y] = dp[x][y]+1;

      if(grid[x-1][y]=='T' && dp[x-1][y]<tdist)
        tdist = dp[x-1][y];

      bfs.push({x-1, y});

    }

    if(x<n-1 && grid[x+1][y]!='X' && dp[x+1][y]==-1){

      dp[x+1][y] = dp[x][y]+1;

      if(grid[x+1][y]=='T' && dp[x+1][y]<tdist)
        tdist = dp[x+1][y];

      bfs.push({x+1, y});

    }

    if(y>0 && grid[x][y-1]!='X' && dp[x][y-1]==-1){

      dp[x][y-1] = dp[x][y]+1;

      if(grid[x][y-1]=='T' && dp[x][y-1]<tdist)
        tdist = dp[x][y-1];

      bfs.push({x, y-1});

    }

    if(y<m-1 && grid[x][y+1]!='X' && dp[x][y+1]==-1){

      dp[x][y+1] = dp[x][y]+1;

      if(grid[x][y+1]=='T' && dp[x][y+1]<tdist)
        tdist = dp[x][y+1];

      bfs.push({x, y+1});

    }
  }
}

int main()
{

  memset(dp, -1, sizeof dp);

  cin >> n >> m >> sx >> sy >> mx >> my;

  for(int i{0}; i<n; i++)
    for(int j{0}; j<m; j++)
      cin >> grid[i][j];

  int t, tx, ty;  cin >> t;

  while(t--){

    cin >> tx >> ty;
    grid[tx][ty] = 'T';

  }
  
  solve();

  if(tdist>=dp[mx][my])
    cout << 0 << "\n";
  else
    cout << dp[mx][my] - tdist << "\n";
  
  return 0;
}
