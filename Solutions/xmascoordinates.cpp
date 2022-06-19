#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize "Ofast"
#define ll long long
#define MOD 1000000007
#define p 31
#define INF 0x3f3f3f3f
#define MAXN 1005
#define pb push_back
#define LSB(S) (S & (-S))
typedef pair<int, int> pii;
typedef pair<pair<int, int>, int> piii;
typedef vector<int> vi;
typedef vector<vector<int>> vii;

int dist[MAXN][MAXN], vis[MAXN][MAXN], n, m;
char arr[MAXN][MAXN];
pii start, endi, present;

void bfs(){
    queue<pii> q;
    q.push({present.first, present.second});
    vis[present.first][present.second]=1;
    dist[present.first][present.second]=0;
    while(!q.empty()){
        int u=q.front().first, v=q.front().second;
        q.pop();
        if(u+1<=n && v<=m && u>=0 && v>=0 && !vis[u+1][v] && arr[u+1][v]!='#'){vis[u+1][v]=1; dist[u+1][v]=dist[u][v]+1; q.push({u+1, v});}
        if(u-1<=n && v<=m && u>=0 && v>=0 && !vis[u-1][v] && arr[u-1][v]!='#'){vis[u-1][v]=1; dist[u-1][v]=dist[u][v]+1; q.push({u-1, v});}
        if(u<=n && v+1<=m && u>=0 && v>=0 && !vis[u][v+1] && arr[u][v+1]!='#'){vis[u][v+1]=1; dist[u][v+1]=dist[u][v]+1; q.push({u, v+1});}
        if(u<=n && v-1<=m && u>=0 && v>=0 && !vis[u][v-1] && arr[u][v-1]!='#'){vis[u][v-1]=1; dist[u][v-1]=dist[u][v]+1; q.push({u, v-1});}
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL);  cout.tie(NULL);
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin >> arr[i][j];
            if(arr[i][j]=='O'){
                start={i, j};
            }
            if(arr[i][j]=='X'){
                endi={i, j};
            }
            if(arr[i][j]=='P'){
                present={i, j};
            }
        }
    }
    bfs();
    if(dist[start.first][start.second]!=0 && dist[endi.first][endi.second]!=0)
        cout << dist[start.first][start.second] + dist[endi.first][endi.second] << "\n";
    else
        cout << -1 << "\n";

    return 0;
}
