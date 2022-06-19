#include <bits/stdc++.h>
using namespace std;

int res[1000][1000], n, m, si, sj, ei, ej;  char arr[1000][1000];

int solve(){

  memset(res, -1, sizeof res);

  queue<pair<int, int>> q;  q.push({si, sj});
  res[si][sj]=0;

  int i, j;
  while(!q.empty()){

    i=q.front().first;  j=q.front().second;
    q.pop();

    if(i>0 && res[i-1][j]==-1 && arr[i-1][j]!='X'){

      res[i-1][j] = res[i][j]+1;
      q.push({i-1, j});

      if(arr[i-1][j]=='e')
        return res[i-1][j]-1;

    }

    if(i<n-1 && res[i+1][j]==-1 && arr[i+1][j]!='X'){

      res[i+1][j] = res[i][j]+1;
      q.push({i+1, j});

      if(arr[i+1][j]=='e')
        return res[i+1][j]-1;

    }

    if(j>0 && res[i][j-1]==-1 && arr[i][j-1]!='X'){

      res[i][j-1] = res[i][j]+1;
      q.push({i, j-1});

      if(arr[i][j-1]=='e')
        return res[i][j-1]-1;

    }

    if(j<m-1 && res[i][j+1]==-1 && arr[i][j+1]!='X'){

      res[i][j+1] = res[i][j]+1;
      q.push({i, j+1});

      if(arr[i][j+1]=='e')
        return res[i][j+1]-1;

    }

  }

  return -1;
}

int main()
{
    
  ios_base::sync_with_stdio(0); cin.tie(NULL);  cout.tie(NULL);

  cin >> n >> m;

  for(int i{0}; i<n; i++){
    for(int j{0}; j<m; j++){

      cin >> arr[i][j];

      if(arr[i][j]=='s'){si=i;  sj=j;}
      if(arr[i][j]=='e'){ei=i;  ej=j;}

    }
  }

  cout << solve() << "\n";
  
  return 0;
}
