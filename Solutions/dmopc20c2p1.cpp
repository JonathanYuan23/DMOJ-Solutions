#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize "Ofast"
#define ll long long
#define ull unsigned long long
#define MOD 1e9+7
#define fi first
#define se second
#define INF 0x3f3f3f3f
#define MAX 3005
#define pb push_back
#define LSB(S) (S & (-S))
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<piii> viii;

int n, start, endi, vis[MAX], res[MAX][1505];
string ord;

void bfs(){
    queue<piii> q;
    q.push({0, {1500, 0}});
    start = 1500, endi = 1500;
    while(!q.empty()){
        int ind = q.front().fi, u = q.front().se.fi, v = q.front().se.se;
        q.pop();
        if(ind == n) continue;
        if(ord[ind]=='^'){
            res[u][v] = 1;
            start = min(start, u); endi = max(endi, u);
            vis[u] = 1;
            if(v+1<n) q.push({ind+1, {u-1, v+1}});
        }
        else if(ord[ind]=='v'){
            res[u+1][v] = 2;
            start = min(start, u+1); endi = max(endi, u+1);
            vis[u+1] = 1;
            if(v+1<n) q.push({ind+1, {u+1, v+1}});
        }
        else{
            res[u][v] = 3;
            start = min(start, u); endi = max(endi, u);
            vis[u] = 1;
            if(v+1<n) q.push({ind+1, {u, v+1}});
        }
    }
    for(int i=start; i<=endi; i++){
        if(!vis[i]) continue;
        for(int j=0; j<n; j++){
            if(res[i][j]==0) cout << ".";
            if(res[i][j]==1) cout << "/";
            if(res[i][j]==2) cout << "\\";
            if(res[i][j]==3) cout << "_";
        }
        cout << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);  cout.tie(NULL);
    // freopen("input.txt", "r", stdin);
    cin >> n >> ord;
    bfs();
    return 0;
}
