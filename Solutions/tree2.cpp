#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize "Ofast"
#define frein freopen("input.txt", "r", stdin)
#define freout freopen("output.txt", "w", stdout)
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define fi first
#define se second
#define INF 0x3f3f3f3f
#define MAX 15
#define pb push_back
#define LSB(S) (S & (-S))
#define sz(x) (int)(x.size())
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<pii, pii> piiii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<piii> viii;
typedef vector<piiii> viiii;

int r, c, mx = -1, grid[MAX][MAX], vis[MAX][MAX], dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
pii dijkstra[MAX][MAX], start, loc;

double dist(int x, int y, int a, int b){
    return sqrt(pow(((double)x-a), 2) + pow(((double)y-b), 2));
}

bool valid(int u, int v){
    return u >= 0 && u < r && v >= 0 && v < c && grid[u][v] != -1;
}

void findMax(){
    double mn = INT_MAX;
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            if(grid[i][j] == mx){
                double curDist = dist(start.se+1, r-start.fi, j+1, r-i);
                if(curDist < mn){
                    loc = {i, j};
                    mn = curDist;
                }
            }
        }  
    }
}

void shortest(){
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            dijkstra[i][j] = {INF, INF};
        }
    }
    memset(vis, 0, sizeof vis);
    priority_queue<piiii, viiii, greater<piiii>> pq;
    pq.push({{0, 0}, {start.fi, start.se}});
    dijkstra[start.fi][start.se] = {0, 0};
    while(!pq.empty()){
        int u = pq.top().se.fi, v = pq.top().se.se, cost = pq.top().fi.fi, edges = pq.top().fi.se;
        pq.pop();
        vis[u][v] = 1;
        for(int i=0; i<4; i++){
            int nu = u + dx[i], nv = v + dy[i];
            if(valid(nu, nv)){
                if(dijkstra[nu][nv].fi > cost + grid[nu][nv]){
                    dijkstra[nu][nv].fi = cost + grid[nu][nv];
                    dijkstra[nu][nv].se = edges + ((grid[nu][nv] > 0) ? 1 : 0);
                    if(!vis[nu][nv]){
                        pq.push({{dijkstra[nu][nv].fi, dijkstra[nu][nv].se}, {nu, nv}});
                    }
                }
                else if(dijkstra[nu][nv].fi == cost + grid[nu][nv]){
                    dijkstra[nu][nv].se = min(dijkstra[nu][nv].se, edges + ((grid[nu][nv] > 0) ? 1 : 0));
                }
            }
        }
    }
    cout << dijkstra[loc.fi][loc.se].se - 1 << '\n';
}

void solve(){
    cin >> r >> c;
    char cell;
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cin >> cell;
            if(cell == '.'){
                grid[i][j] = 0;
            }
            else if(cell == 'X'){
                grid[i][j] = -1;
                start = {i, j};
            }
            else {
                grid[i][j] = cell - '0';
                mx = max(grid[i][j], mx);
            }
        }
    }
    findMax();
    shortest();
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL);  cout.tie(NULL);
    solve();
    return 0;
}
