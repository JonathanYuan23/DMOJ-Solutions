#pragma GCC optimize "Ofast"
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MOD 1000000009
#define p 31
#define INF 0x3f3f3f3f
#define MAXN 105
#define pb push_back
#define LSB(S) (S & (-S))
typedef vector<int> vi;
typedef vector<vector<int>> vii;

vector<int> graph[MAXN]; int vis[MAXN], dist[MAXN], n, u, v, startnode;

int dfs(int node, int prev){
    vis[node]=1;
    int ans=0;
    for(auto x: graph[node]){
        if(!vis[x]){
            dist[x]=dist[node]+1;
            ans=dfs(x, node);
            if(ans>0) break;
        } else if(vis[x]==1){
            return dist[node]-dist[x]+1;
        }
    }
    vis[node]=2;
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL);  cout.tie(NULL);

    for(int i=0; i<5; i++){
        cin >> n;
        for(int j=0; j<n; j++){
            cin >> u >> v;
            graph[u].push_back(v);
            if(j==0) startnode=u;
        }
        cout << dfs(startnode, -1) << "\n";
        memset(vis, 0, sizeof vis);
        memset(dist, 0, sizeof dist);
        for(int j=0; j<MAXN; j++) graph[j].clear();
    }
    
    return 0;
}
