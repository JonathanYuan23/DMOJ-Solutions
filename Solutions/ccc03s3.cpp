#include <bits/stdc++.h>
using namespace std;

int rcount{0}, rooms{0};

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

vector<int> order;

void bfs(char **grid, bool **v1, int i, int j, int n , int m){

  queue<pair <int, int>> pos;
  pos.push({i, j});

  v1[i][j] = true;
  rcount++;

  while(!(pos.empty())){

    i = pos.front().first;
    j = pos.front().second;

    pos.pop();

    for(int k{0}; k<4; k++){

      int u = i + dx[k];
      int v = j + dy[k];

      if(u>=0 && v>=0 && u<n && v<m && grid[u][v]=='.' && v1[u][v]==false){

        pos.push({u, v});
        v1[u][v] = true;
        rcount++;

      }
    }
  }
}

void flooring(int space){

  sort(order.begin(), order.end(), greater<int>());

  for(auto x: order){

    if(space - x >= 0){

      space -= x;
      rooms++;

    }

    else
      break;

  }

  if(rooms == 0 || rooms > 1)
    cout << rooms << " rooms, " << space << " square metre(s) left over\n";
  else
    cout << rooms << " room, " << space << " square metre(s) left over\n";
}

void findRooms(char **grid, bool **v1, int n , int m){

  for(int i{0}; i<n; i++){
    for(int j{0}; j<m; j++){

      if(!v1[i][j] && grid[i][j]=='.'){

        bfs(grid, v1, i, j, n, m);
        order.push_back(rcount);
        rcount=0;

      }
    }
  }
}

int main() {

  ios_base::sync_with_stdio(false); cin.tie(NULL);  cout.tie(NULL);

  int space, row, col; cin >> space >> row >> col;

  char **grid = new char*[row];

  for(int i{0}; i<row; i++)
    grid[i] = new char[col];

  for(int i{0}; i<row; i++)
    for(int j{0}; j<col; j++)
      cin >> grid[i][j];

  bool **v1 = new bool*[row];

  for(int i{0}; i<row; i++)
    v1[i] = new bool[col];

  for(int i{0}; i<row; i++)
    for(int j{0}; j<col; j++)
      v1[i][j] = false;  

  findRooms(grid, v1, row, col);

  flooring(space);
  
  return 0;
}
