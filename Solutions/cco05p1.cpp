#include <bits/stdc++.h>
using namespace std;

bool arr[10][100][100], res[100][100], visited[100][100];

int grid[100][100], nums[3], n, m;

unordered_map<int, vector<int>> firstRow;

void init(){

  memset(arr, 0, sizeof arr);
  memset(res, 0, sizeof res);
  memset(nums, -1, sizeof nums);

}

bool valid(int i, int j){

  return i>=0 && i<m && j>=0 && j<n && res[i][j] == 1 && !visited[i][j];

}

bool paths(int num){

  queue<pair<int, int>> q;
  q.push({0, num});
  visited[0][num] = true;

  int x, y;
  while(!q.empty()){

    x = q.front().first;  y = q.front().second;
    q.pop();

    if(x==m-1)
      return true;

    if(valid(x+1, y)){q.push({x+1, y}); visited[x+1][y]=true;}
    if(valid(x-1, y)){q.push({x-1, y}); visited[x-1][y]=true;}
    if(valid(x, y+1)){q.push({x, y+1}); visited[x][y+1]=true;}
    if(valid(x, y-1)){q.push({x, y-1}); visited[x][y-1]=true;}


  }

  return false;
}

void solve(){

  for(int i{0}; i<=9; i++){
    for(int j{0}; j<=9; j++){
      for(int k{0}; k<=9; k++){

        memset (res, 0, sizeof res);

        if(firstRow[i].size()>0 || firstRow[j].size()>0 || firstRow[k].size()>0){

          for(int l{0}; l<m; l++){
            for(int t{0}; t<n; t++){

              res[l][t] |= arr[i][l][t];
              res[l][t] |= arr[j][l][t];
              res[l][t] |= arr[k][l][t];

            }
          }

          memset(visited, 0, sizeof visited);
          
          for(auto x: firstRow[i]){
            if(paths(x)){nums[0] = i;  nums[1] = j;  nums[2] = k;  return;}
          }

          for(auto x: firstRow[j]){
            if(paths(x)){nums[0] = i;  nums[1] = j;  nums[2] = k;  return;}
          }

          for(auto x: firstRow[k]){
            if(paths(x)){nums[0] = i;  nums[1] = j;  nums[2] = k;  return;}
          }
          
        }

        else
          continue;
      }
    }
  }

}

int main()
{

  init();

  cin >> n >> m;

  for(int i{0}; i<m; i++){
    for(int j{0}; j<n; j++){

      cin >> grid[i][j];

      arr[grid[i][j]][i][j] = true;

      if(i==0)
        firstRow[grid[i][j]].push_back(j);

    }
  }

  solve();

  if(nums[0]==-1)
    cout << -1 << " " << -1 << " " << -1 << "\n";
  else
    cout << nums[0] << " " << nums[1] << " " << nums[2] << "\n";

  return 0;
}
