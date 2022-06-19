#pragma GCC optimize "Ofast"
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MOD 1000000009
#define p 31
#define INF 0x3f3f3f3f
#define MAXN 1005
#define pb push_back
#define LSB(S) (S & (-S))
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vii;

vector<int> graph[MAXN], tin, low, vis;
int n, m, u, v, e, t, bridges;

void dfs(int node, int pre){
    vis[node]=1;
    tin[node]=low[node]=t++;
    for(auto x: graph[node]){
        if(x==pre) continue;
        if(vis[x]) low[node] = min(low[node], tin[x]);
        else{
            dfs(x, node);
            low[node] = min(low[node], low[x]);
            if(low[x]>tin[node]) bridges++;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL);  cout.tie(NULL);
    for(int testcase=0; testcase<5; testcase++){
        bridges=t=0;
        cin >> n >> m;
        for(int i=0; i<m; i++){
            cin >> u >> v;
            graph[u].pb(v);
            graph[v].pb(u);
        }
        vis.assign(n+1, 0);
        tin.assign(n+1, -1);
        low.assign(n+1, -1);
        for(int i=1; i<=n; i++){
            if(!vis[i])
                dfs(i, -1);
        }
        cout << bridges << "\n";
        for(int i=0; i<=n; i++) graph[i].clear();
    }

    return 0;
}
