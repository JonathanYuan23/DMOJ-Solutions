#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize "Ofast"
#define ll long long
#define MOD 1000000009
#define p 31
#define INF 0x3f3f3f3f
#define MAXN 15
#define pb push_back
#define LSB(S) (S & (-S))
typedef pair<int, int> pii;
typedef pair<pair<int, int>, int> piii;
typedef vector<int> vi;
typedef vector<vector<int>> vii;

int vis[MAXN][MAXN]; char grid[MAXN][MAXN]; pii x={-1, -1}, y={-1, -1};

bool ok(int row, int col){
    return row>=0 && row<10 && col>=0 && col<10 && grid[row][col]!='#' && !vis[row][col];
}

void bfs(){
    memset(vis, 0, sizeof vis);
    vis[x.first][x.second]=1;
    queue<piii> q;
    q.push({{x.first, x.second}, 0});
    while(!q.empty()){
        int u=q.front().first.first, v=q.front().first.second, e=q.front().second;
        q.pop();

        if(u==y.first && v==y.second){cout << e << "\n"; return;}

        //adj
        if(ok(u-1, v)){vis[u-1][v]=1; q.push({{u-1, v}, e+1});}
        if(ok(u+1, v)){vis[u+1][v]=1; q.push({{u+1, v}, e+1});}
        if(ok(u, v-1)){vis[u][v-1]=1; q.push({{u, v-1}, e+1});}
        if(ok(u, v+1)){vis[u][v+1]=1; q.push({{u, v+1}, e+1});}

        //diag
        if(ok(u-1, v+1)){vis[u-1][v+1]=1; q.push({{u-1, v+1}, e+1});}
        if(ok(u+1, v-1)){vis[u+1][v-1]=1; q.push({{u+1, v-1}, e+1});}
        if(ok(u-1, v-1)){vis[u-1][v-1]=1; q.push({{u-1, v-1}, e+1});}
        if(ok(u+1, v+1)){vis[u+1][v+1]=1; q.push({{u+1, v+1}, e+1});}        
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL);  cout.tie(NULL);
    for(int t=0; t<5; t++){
        for(int i=0; i<10; i++){
            for(int j=0; j<10; j++){
                cin >> grid[i][j];
                if(grid[i][j]=='X'){
                    if(x.first==-1) x={i, j};
                    else y={i, j};
                }
            }
        }
        for(int i=0; i<10; i++) cin >> grid[0][0];
        bfs();
        x={-1, -1}; y={-1, -1};
    }

    return 0;
}
