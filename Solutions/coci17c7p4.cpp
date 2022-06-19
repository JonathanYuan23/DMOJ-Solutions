#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize "Ofast"
#define frein freopen("input.txt", "r", stdin)
#define freout freopen("output.txt", "w", stdout)
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define nl '\n'
#define fi first
#define se second
#define INF 0x3f3f3f3f
#define MAX 1005
#define IMX INT_MAX
#define IMN INT_MIN
#define LLMX LONG_LONG_MAX
#define LLMN LONG_LONG_MIN
#define pb push_back
#define pf push_front
#define LSB(x) (x & (-x))
#define sz(x) (ll)(x.size())
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<pii, pii> piiii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<piii> viii;
typedef vector<piiii> viiii;  

struct Bucket{
    int t, b, l, r;
} buckets[MAX * 100];

int n, m, k = 0, grouping[MAX][MAX], vis[MAX][MAX];
char grid[MAX][MAX];

bool compare(const piii &a, const piii &b){
    if(a.se.fi == b.se.fi) return a.se.se < b.se.se;
    return a.se.fi > b.se.fi;
}   

Bucket bounds(pii cell){
    Bucket ret;
    for(int i=cell.fi-1; i>=0; i--){
        if(grid[i][cell.se] == '-'){
            ret.t = i;
            break;
        }
    }
    for(int i=cell.fi+1; i<n; i++){
        if(grid[i][cell.se] == '-'){
            ret.b = i;
            break;
        }
    }
    for(int j=cell.se-1; j>=0; j--){
        if(grid[cell.fi][j] == '|'){
            ret.l = j;
            break;
        }
    }
    for(int j=cell.se+1; j<m; j++){
        if(grid[cell.fi][j] == '|'){
            ret.r = j;
            break;
        }
    }
    return ret;
}

void perimeter(int group){
    int l = buckets[group].l, r = buckets[group].r, t = buckets[group].t, b = buckets[group].b;
    for(int j = l; j <= r; j++) grouping[t][j] = grouping[b][j] = group;
    for(int i = t; i <= b; i++) grouping[i][l] = grouping[i][r] = group;
}

int get_next(pii cur, pii par, int dir){
    if(grouping[cur.fi][cur.se] > 0) return grouping[cur.fi][cur.se];
    if(grid[cur.fi][cur.se] == '+'){
        int i = cur.fi, j = cur.se;
        //down
        if(i + 1 < n && grid[i+1][j] != '.' && !(i + 1 == par.fi && j == par.se)) return get_next({i+1, j}, cur, 0);
        //left
        if(j - 1 >= 0 && grid[i][j-1] != '.' && !(i == par.fi && j - 1 == par.se)) return get_next({i, j-1}, cur, 1);
        //right
        if(j + 1 < m && grid[i][j+1] != '.' && !(i == par.fi && j + 1 == par.se)) return get_next({i, j+1}, cur, 2);
    }
    else{
        // down
        if(dir == 0) return get_next({cur.fi+1, cur.se}, cur, dir);
        //left
        if(dir == 1) return get_next({cur.fi, cur.se-1}, cur, dir);
        //right
        if(dir == 2) return get_next({cur.fi, cur.se+1}, cur, dir);
    }
    return 0;
}

void create(int group){
    int l = buckets[group].l, r = buckets[group].r, t = buckets[group].t, b = buckets[group].b;
    for(int i=b-1; i>t; i--){
        if(l > 0){
            if(grid[i][l-1] == '-'){
                int next = get_next({i, l-1}, {i, l}, 1);
                create(next);
            }
        }
        if(r < m){
            if(grid[i][r+1] == '-'){
                int next = get_next({i, r+1}, {i, r}, 2);
                create(next);
            }
        }
    }
    cout << group << nl;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);  cout.tie(NULL);
    cin >> n >> m;
    for(int i=0; i<n; i++) for(int j=0; j<m; j++) cin >> grid[i][j];
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(vis[i][j]) continue;
            vis[i][j] = 1;
            if(isdigit(grid[i][j])){
                string s = "";
                s += grid[i][j];
                for(int c=j+1; c<m && isdigit(grid[i][c]); c++){
                    vis[i][c] = 1;
                    s += grid[i][c];
                }
                k++;
                buckets[stoi(s)] = bounds({i, j});
                perimeter(stoi(s));
            }
        }
    }
    create(1);
    
    return 0;
};
