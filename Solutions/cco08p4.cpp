#include <bits/stdc++.h>
#define N 1000
using namespace std;

char grid[N][N]; bool visited[N][N];
int n, m, colour=0;

map<pair<int, int>, vector<pair<int, int>>> graph;

bool valid(int i, int j){

  return i>=0 && i<n && j>=0 && j<m;

}

void bfs(int i, int j){

  queue<pair<int, int>> q;
  q.push({i, j});
  visited[i][j] = true;

  int a, b, c, d;
  while(!q.empty()){

    a = q.front().first;  b = q.front().second;
    
    q.pop();

    for(auto x: graph[{a, b}]){

      c = x.first; d = x.second;

      if(!visited[c][d]){

        visited[c][d] = true;
        q.push({c, d});

      }
    }
  }

  colour++;
}

int main()
{

  cin >> n >> m;

  for(int i{0}; i<n; i++){
    for(int j{0}; j<m; j++){

      cin >> grid[i][j];

      if(grid[i][j]=='S'){
        if(valid(i+1, j)){

          graph[{i, j}].push_back({i+1, j});
          graph[{i+1, j}].push_back({i, j});

        }
      }
      if(grid[i][j]=='N'){
        if(valid(i-1, j)){

          graph[{i, j}].push_back({i-1, j});
          graph[{i-1, j}].push_back({i, j});

        }
      }
      if(grid[i][j]=='W'){
        if(valid(i, j-1)){

          graph[{i, j}].push_back({i, j-1});
          graph[{i, j-1}].push_back({i, j});

        }
      }
      if(grid[i][j]=='E'){

        if(valid(i, j+1)){

          graph[{i, j}].push_back({i, j+1});
          graph[{i, j+1}].push_back({i, j});

        }
      }
    }
  }

  memset(visited, 0, sizeof visited);

  for(int i{0}; i<n; i++){
    for(int j{0}; j<m; j++){
      if(!visited[i][j]){

        bfs(i, j);

      }
    }
  }

  cout << colour << "\n";

  return 0;
}
