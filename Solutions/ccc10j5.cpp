#include <bits/stdc++.h>
using namespace std;

int dist[8][8];

int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};

int minKnight(char ** grid, int i, int j, int n, int m){

  queue<pair<int, int>> knights;

  knights.push({i, j});

  dist[i][j] = 0;

  while(!knights.empty()){

    i = knights.front().first;
    j = knights.front().second;

    if(grid[i][j] == 'b')
      return dist[i][j];

    knights.pop();

    for(int k{0}; k<8; k++){

      int u = i + dx[k];
      int v = j + dy[k];

      if(u>=0 && v>=0 && u<n && v<m){
        dist[u][v] = dist[i][j] + 1;
        knights.push({u, v});
      }
    }
  }
  return -1;
}

int main() {

  int n=8, m=8;

  char **grid = new char*[n];

  for(int i{0}; i<n; i++)
    grid[i] = new char[m];

  for(int i{0}; i<n; i++){
    for(int j{0}; j<m; j++){
      grid[i][j] = '0';
    }
  }

  int pos1, pos2, pos3, pos4;  cin >> pos1 >> pos2 >> pos3 >> pos4;

  grid[n-pos2][pos1-1] = 'a';

  grid[n-pos4][pos3-1] = 'b';

  memset(dist, -1, sizeof dist);
  
  cout << minKnight(grid, n-pos2, pos1-1, n, m) << endl;

  return 0;
}
