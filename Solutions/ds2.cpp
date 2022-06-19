#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize "Ofast"
#define ll long long
#define ull unsigned long long
#define MOD 1e9+7
#define fi first
#define se second
#define INF 0x3f3f3f3f
#define MAX 100005
#define pb push_back
#define LSB(S) (S & (-S))
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<piii> viii;

int n, m, vis[MAX], p[MAX], ranking[MAX];
vi graph[MAX], mst; 
vii edges;

void dfs(int node){
    vis[node] = 1;
    for(auto to: graph[node]) if(!vis[to]) dfs(to);
}

int findSet(int i) { 
    return (p[i] == i) ? i : (p[i] = findSet(p[i])); 
}

void unionSet(int u, int v){
    if(ranking[u] > ranking[v]) p[v] = u;
    else{
        p[u] = v;
        if(ranking[u] == ranking[v]) ranking[v]++;
    }
}

void solve(){
    for(int i=1; i<=n; i++){
        p[i] = i;
        if(!vis[i]){
            cout << "Disconnected Graph\n";
            return;
        }
    }
    int tot = 0, x, y;
    for(int i=0; i<edges.size(); i++){
        if(tot == n-1) break;
        x = findSet(edges[i].fi); 
        y = findSet(edges[i].se);
        if(x != y){
            tot++;
            unionSet(x, y);
            mst.pb(i+1);
        }
    }
    for(auto edge: mst) cout << edge << '\n';
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);  cout.tie(NULL);
    // freopen("input.txt", "r", stdin);
    cin >> n >> m;
    for(int i=0, u, v; i<m; i++){
        cin >> u >> v;
        graph[u].pb(v);
        graph[v].pb(u);
        edges.pb({u, v});
    }
    dfs(1);
    solve();
        
    return 0;
}
