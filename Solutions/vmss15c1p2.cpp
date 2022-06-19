#pragma GCC optimize "Ofast"
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MOD 1000000009
#define p 31
#define INF 0x3f3f3f3f
#define MAXN 105
#define pb push_back
#define LSB(S) (S & (-S))
typedef pair<int, int> pii;
typedef pair<pair<int, int>, int> piii;
typedef vector<int> vi;
typedef vector<vector<int>> vii;

int r, c, vis[MAXN][MAXN];
char grid[MAXN][MAXN];

bool ok(int row, int col){
    return row>=0 && row<r && col>=0 && col<c && grid[row][col]!='X' && !vis[row][col];
}

void bfs(int row, int col){
    vis[row][col]=1;
    queue<pii> q;
    q.push({row, col});
    while(!q.empty()){
        int u=q.front().first, v=q.front().second;
        q.pop();
        if(ok(u-1, v)){vis[u-1][v]=1; q.push({u-1, v});}
        if(ok(u+1, v)){vis[u+1][v]=1; q.push({u+1, v});}
        if(ok(u, v-1)){vis[u][v-1]=1; q.push({u, v-1});}
        if(ok(u, v+1)){vis[u][v+1]=1; q.push({u, v+1});}
    }
}

void exp(){
    memset(vis, 0, sizeof vis);
    int ans=0;
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            if(ok(i, j)){bfs(i, j); ans++;}
        }
    }
    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL);  cout.tie(NULL);
    cin >> r >> c;
    for(int i=0; i<r; i++)
        for(int j=0; j<c; j++)
            cin >> grid[i][j];
    exp();

    return 0;
}
