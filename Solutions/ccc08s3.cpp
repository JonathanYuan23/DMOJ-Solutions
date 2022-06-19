#include<bits/stdc++.h> 
using namespace std; 

char sects[20][20]; int visited[20][20];

int r, c;

void solve(){

  queue<pair<int, int>> bfs;
  bfs.push({0, 0});
  visited[0][0] = 1;

  while(!bfs.empty()){

    int i = bfs.front().first;
    int j = bfs.front().second;

    bfs.pop();

    if(sects[i][j]=='+'){

      if(i>0 && sects[i-1][j]!='*' && visited[i-1][j]==-1){

        visited[i-1][j] = visited[i][j] + 1;
        bfs.push({i-1, j});

      }
      if(i<r-1 && sects[i+1][j]!='*' && visited[i+1][j]==-1){

        visited[i+1][j] = visited[i][j] + 1;
        bfs.push({i+1, j});

      }
      if(j>0 && sects[i][j-1]!='*' && visited[i][j-1]==-1){

        visited[i][j-1] = visited[i][j] + 1;
        bfs.push({i, j-1});

      }
      if(j<c-1 && sects[i][j+1]!='*' && visited[i][j+1]==-1){

        visited[i][j+1] = visited[i][j] + 1;
        bfs.push({i, j+1});

      }

    }
    if(sects[i][j]=='-'){

      if(j>0 && sects[i][j-1]!='*' && visited[i][j-1]==-1){

        visited[i][j-1] = visited[i][j] + 1;
        bfs.push({i, j-1});

      }
      if(j<c-1 && sects[i][j+1]!='*' && visited[i][j+1]==-1){

        visited[i][j+1] = visited[i][j] + 1;
        bfs.push({i, j+1});

      }      

    }
    if(sects[i][j]=='|'){

      if(i>0 && sects[i-1][j]!='*' && visited[i-1][j]==-1){

        visited[i-1][j] = visited[i][j] + 1;
        bfs.push({i-1, j});

      }
      if(i<r-1 && sects[i+1][j]!='*' && visited[i+1][j]==-1){

        visited[i+1][j] = visited[i][j] + 1;
        bfs.push({i+1, j});

      }
    }
  }
}

int main() 
{ 

  int n;  cin >> n;

  while(n--){

    memset(visited, -1, sizeof(visited));

    cin >> r >> c;

    for(int i{0}; i<r; i++)
      for(int j{0}; j<c; j++)
        cin >> sects[i][j];

    solve();
    cout << visited[r-1][c-1] << "\n";

  }

	return 0; 
}
