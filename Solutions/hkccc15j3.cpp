#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
#define INF 1<<30
using namespace std;
const int MAXN = 105;

int board[MAXN][MAXN];

int main(){

	ios_base::sync_with_stdio(0); cin.tie(NULL);  cout.tie(NULL);
  memset(board, 0, sizeof 0);
  
  int n, m, x, y, a, b; 
  cin >> n >> m;

  for(int i=0; i<m; i++){

    cin >> x >> y;  x--;  y--;
    board[x][y] = 1;

    //vertical
    for(int j=x; j>=0; j--) board[j][y]=1;
    for(int j=x; j<n; j++) board[j][y]=1;

    //horizontal
    for(int j=y; j>=0; j--) board[x][j]=1;
    for(int j=y; j<n; j++) board[x][j]=1;

    //diagonals
    a=x,  b=y; while(a>=0 && b>=0){board[a][b]=1;  a--;  b--;}
    a=x;  b=y; while(a>=0 && b<n){board[a][b]=1; a--; b++;}
    a=x;  b=y; while(a<n && b>=0){board[a][b]=1; a++; b--;}
    a=x;  b=y; while(a<n && b<n){board[a][b]=1; a++; b++;}

  }

  int ans=0;  
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){

      if(board[i][j]==0) ans++;

    }
  }
  
  cout << ans << "\n";

  return 0;
}
