#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize "Ofast"
#define ll long long
#define MOD 1000000009
#define p 31
#define INF 0x3f3f3f3f
#define MAXN 10'000'005
#define pb push_back
#define LSB(S) (S & (-S))
typedef pair<int, int> pii;
typedef pair<pair<int, int>, int> piii;
typedef vector<int> vi;
typedef vector<vector<int>> vii;

int x, y, vis[MAXN];

bool ok(int u){
    return u>=1 && u<=MAXN;
}

void solve(){
    cin >> x >> y;
    vis[x]=1;
    queue<pii> q;
    q.push({x, 0});
    while(!q.empty()){
        int u=q.front().first, e=q.front().second; q.pop();
        if(u==y){cout << e << "\n"; return;}
        if(ok(3*u) && !vis[3*u]){q.push({3*u, e+1}); vis[3*u]=1;}
        if(ok(u-1) && !vis[u-1]){q.push({u-1, e+1}); vis[u-1]=1;}
        if(ok(u-3) && !vis[u-3]){q.push({u-3, e+1}); vis[u-3]=1;}
        if(u%2==0 && ok(u/2) && !vis[u/2]){q.push({u/2, e+1}); vis[u/2]=1;}
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL);  cout.tie(NULL);
    solve();
    return 0;
}
