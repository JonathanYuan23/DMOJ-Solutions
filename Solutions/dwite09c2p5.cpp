#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize "Ofast"
#define ll long long
#define ull unsigned long long
#define MOD 1e9+7
#define fi first
#define se second
#define INF 0x3f3f3f3f
#define MAX 25
#define pb push_back
#define LSB(S) (S & (-S))
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<piii> viii;

int R, C, vis[MAX][MAX];
char room[MAX][MAX];
pii starts[25], portals[25], nxt[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

bool valid(int r, int c){
    return r>=0 && r<R && c>=0 && c<C && room[r][c] != '#' && !vis[r][c];
}

void bfs(int start, vi &res){
    queue<pii> q;
    q.push({starts[start].fi, starts[start].se});
    memset(vis, 0, sizeof vis);
    vis[starts[start].fi][starts[start].se] = 1;
    while(!q.empty()){
        int r = q.front().fi, c = q.front().se;
        q.pop();
        char cell = room[r][c];
        if(isdigit(cell) && cell-'0' != start) res.pb(cell-'0');
        if(isalpha(cell) && islower(cell)){
            if(valid(portals[cell-'a'].fi, portals[cell-'a'].se)){
                q.push({portals[cell-'a'].fi, portals[cell-'a'].se});
                vis[portals[cell-'a'].fi][portals[cell-'a'].se] = 1;
            }
        }
        for(int i=0; i<4; i++){
            int nr = r+nxt[i].fi, nc = c+nxt[i].se;
            if(valid(nr, nc)){
                q.push({nr, nc});
                vis[nr][nc] = 1;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);  cout.tie(NULL);
    // freopen("input.txt", "r", stdin);
    cin >> R >> C;
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            cin >> room[i][j];
            if(isalpha(room[i][j]) && isupper(room[i][j])){
                char c = tolower(room[i][j]);
                portals[c-'a'] = {i, j};
            }
            if(isdigit(room[i][j])){
                starts[room[i][j]-'0'] = {i, j};
            }
        }
    }
    for(int i=1; i<=5; i++){
        vi res;
        bfs(i, res);
        cout << i << ":";
        sort(res.begin(), res.end());
        for(int j=0; j<res.size(); j++){
            cout << res[j];
            if(j<res.size()-1) cout << " ";
        }
        cout << "\n";
    }
    
    return 0;
}
