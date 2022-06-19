#pragma GCC optimize "Ofast"
#include <bits/stdc++.h>
using namespace std; using pii = pair<int, int>;  using piii = pair<int, pii>;  using piiii = pair<pii, pii>;  using vi = vector<int>;  using vii = vector<pii>;  using viii = vector<piii>;  using viiii = vector<piiii>; using ll = long long; using ull = unsigned long long; 
#define frein freopen("input.txt", "r", stdin)
#define freout freopen("output.txt", "w", stdout)
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define pf push_front
#define ppb pop_back
#define LSB(x) (x & (-x))
#define sz(x) (int)(x.size())
#define ms(a, b) memset(a, b, sizeof a)

const int MOD = 1000000007, INF = 0x3f3f3f3f, MX = 1<<20, IMX = INT_MAX, IMN = INT_MIN;
const long long LLMX = LONG_LONG_MAX, LLMN = LONG_LONG_MIN;
const char nl = '\n';

int row, col, a, b, c, start, idx, grid[10][10], grid2[10][10], vis[MX];
bool notEden[MX];
vi adj[MX];

int neighbours(int r, int c){
    return grid[r-1][c-1] + grid[r-1][c] + grid[r-1][c+1] + grid[r][c-1] + grid[r][c+1] + grid[r+1][c-1] + grid[r+1][c] + grid[r+1][c+1];
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL);  cout.tie(NULL); 
    cin >> row >> col >> a >> b >> c;
    // iterate through all possible generations
    for(int mask=0; mask<1<<(row*col); mask++){
        // each generation is originally an Eden
        idx = 0;
        // convert mask to array representation
        for(int i=1; i<=row; i++){
            for(int j=1; j<=col; j++){ 
                grid[i][j] = ((mask & (1<<idx)) ? 1 : 0);
                idx++;
            }
        }
        // convert next generation after mask to binary
        idx = 0, start = 0;
        for(int i=1; i<=row; i++){
            for(int j=1; j<=col; j++){
                int sum = neighbours(i, j);
                if(grid[i][j]){
                    if(sum < a || sum > b) grid2[i][j] = 0;
                    else grid2[i][j] = 1;
                }
                else{
                    if(sum > c) grid2[i][j] = 1;
                    else grid2[i][j] = 0;
                }
                start += grid2[i][j] * (1 << idx);
                idx++;
            }
        }
        // add edge from new generation to mask, new generation can no longer be an Eden
        adj[start].pb(mask); notEden[start] = 1;
    }
    idx = 0, start = 0;
    for(int i=1; i<=row; i++){
        for(int j=1, cell; j<=col; j++){
            char ch; cin >> ch;
            cell = (ch == '*') ? 1 : 0;
            start += cell * (1 << idx), idx++;
        }
    }
    memset(vis, -1, sizeof vis);
    vis[start] = 0;
    queue<int> q; q.push(start);
    while(!q.empty()){
        int mask = q.front(); q.pop();
        for(auto &next: adj[mask]){
            if(vis[next] == -1){
                vis[next] = vis[mask] + 1;
                q.push(next);
                if(!notEden[next]){
                    cout << vis[next] << nl;
                    return 0;
                }
            }
        }
    }
    cout << ((!notEden[start]) ? 0 : -1) << nl;
    return 0;
}
