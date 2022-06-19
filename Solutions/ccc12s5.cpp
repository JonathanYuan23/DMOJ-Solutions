#include <bits/stdc++.h>
using namespace std;

int numPaths(int **arr, int curRow, int curCol, int R, int C, int **paths){

  if(arr[curRow][curCol]==1){
    return 0;
  }

  if(arr[curRow][curCol]==-1){
    return 1;
  }

  if(curRow==R){
    return numPaths(arr, curRow, curCol+1, R, C, paths);
  }

  if(curCol==C){
    return numPaths(arr, curRow+1, curCol, R, C, paths);
  }

  if(paths[curRow][curCol]==0)
    paths[curRow][curCol] = numPaths(arr, curRow, curCol+1, R, C, paths) + numPaths(arr, curRow+1, curCol, R, C, paths);
  
  return paths[curRow][curCol];
}

int main() {

  cin.sync_with_stdio(0); cin.tie(0);
  cout.sync_with_stdio(0);  cout.tie(0);

  int R, C;     cin >> R >> C;

  int **n = new int*[R];
  for(int i{0}; i<R; i++){
      n[i] = new int[C];
  }

  for(int i{0}; i<R; i++){
      for(int j{0}; j<C; j++){
          n[i][j] = 0;
      }
  }

  int **paths = new int*[R];
  for(int i{0}; i<R; i++){
      paths[i] = new int[C];
  }

  for(int i{0}; i<R; i++){
      for(int j{0}; j<C; j++){
          paths[i][j] = 0;
      }
  }

  int K, r, c;    cin >> K;

  while(K--){
    cin >> r >> c;

    n[r-1][c-1] = 1;
  }

  n[R-1][C-1] = -1;

  int path = numPaths(n, 0, 0, R-1, C-1, paths);

  cout << path << endl;

  return 0;
}
