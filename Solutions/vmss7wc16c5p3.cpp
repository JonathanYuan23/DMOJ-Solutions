#pragma GCC optimize "Ofast"
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MOD 1000000009
#define p 31
#define INF 0x3f3f3f3f
#define MAXN 10005
#define pb push_back
#define LSB(S) (S & (-S))
#define um unordered_map
typedef vector<string> vs;
typedef vector<int> vi;

vi graph[MAXN]; int dist[MAXN], ans=INT_MIN, V;

void dfs(int node, int prev, int mx){
    dist[node]=mx;
    if(dist[node]>ans){
        ans=mx;  V=node;
    }
    for(auto x: graph[node]){
        if(x!=prev){
            dfs(x, node, mx+1);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL);  cout.tie(NULL);
    
    int n, u, v;  
    cin >> n;
    for(int i=0; i<n-1; i++){ 
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    dfs(1, -1, 0);
    ans=INT_MIN;
    dfs(V, -1, 0);
    cout << ans << "\n";

    return 0;
}
