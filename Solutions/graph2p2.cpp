//#pragma GCC optimize "Ofast"
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MOD 1000000009
#define p 31
#define INF 0x3f3f3f3f
#define MAXN 1005
#define pb push_back
#define LSB(S) (S & (-S))
typedef vector<int> vi;
typedef vector<vector<int>> vii;

int vis[MAXN], n, v;   vector<int> graph[MAXN];

int dfs(int node, int prev){
    vis[node]=1;
    bool ans=0;
    for(auto x: graph[node]){
        if(!vis[x]){
            ans|=dfs(x, node);
            if(ans) break;
        } else if(vis[x]==1){
            return ans=1;
        }
    }
    vis[node]=2;
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL);  cout.tie(NULL);

    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> v;
            if(v) graph[i].push_back(j);
        }
    }
    bool ans=0;
    for(int i=0; i<n; i++){
        if(graph[i].size()!=0 && !vis[i]){
            ans|=dfs(i, -1);
            if(ans){
                cout << "NO\n"; 
                return 0;
            }
        }
    }
    cout << "YES\n";

    return 0;
}
