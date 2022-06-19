#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize "Ofast"
#define ll long long
#define ull unsigned long long
#define MOD 1e9+7
#define fi first
#define se second
#define INF 0x3f3f3f3f
#define MAXN 35
#define pb push_back
#define LSB(S) (S & (-S))
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<piii> viii;

int n, cycle;
bool adj[MAXN][MAXN], vis[MAXN];

void dfs(int u, int start){
    vis[u] = 1;
    for(int i=1; i<=n; i++){
        if(!adj[u][i]) continue;
        if(start == i) cycle++;
        else if(!vis[i] && i>start) dfs(i, start);
    }
    vis[u] = 0;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);  cout.tie(NULL);
    // freopen("input.txt", "r", stdin);
    cin >> n;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            cin >> adj[i][j];
    for(int i=1; i<=n; i++) dfs(i, i);
    cout << cycle << "\n";
    return 0;
}
