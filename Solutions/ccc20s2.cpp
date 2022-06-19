#include <bits/stdc++.h>
using namespace std;

int grid[1001][1001]; bool visited[1001][1001];
unordered_map<int, vector<int>> facts;

int r, c;

bool solve(int n, int m){

  if(n==r && m==c)
    return true;

  if(visited[n][m])
    return false;

  bool end = false; int x, y;

  visited[n][m] = true;

  if(facts.find(grid[n][m])==facts.end()){

    for(int i{1}; i*i<=grid[n][m];  i++){

      if(end)
        return true;

      if(grid[n][m]%i==0){

        x = i;  y = grid[n][m]/i;
        facts[grid[n][m]].push_back(x);

        if(x<=r && y<=c)
          end |= solve(x, y);

        if(end)
          return true;
        
        if(y<=r && x<=c)
          end |= solve(y, x);

      }

    }
  }
  else{

    for(auto t: facts[grid[n][m]]){

      x = t;  y = grid[n][m]/t;

      if(end)
        return true;

      if(x<=r && y<=c)
        end |= solve(x, y);
        
      if(end)
        return true;

      if(y<=r && x<=c)
        end |= solve(y, x);

    }
  }
  
  return end;
}

int main()
{

  cin >> r >> c;

  for(int i{1}; i<=r; i++)
    for(int j{1}; j<=c; j++)
      cin >> grid[i][j];

  memset(visited, 0, sizeof visited);

  if(solve(1, 1))
    cout << "yes\n";
  else
    cout << "no\n";
  
  return 0;
}
