#pragma GCC optimize "Ofast"
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MOD 1000000009
#define p 31
#define INF 0x3f3f3f3f
#define MAXN 100005
#define pb push_back
#define LSB(S) (S & (-S))
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vii;

vector<int> graph[MAXN]; vector<pii> boxen;
int vis[MAXN];

int dfs(int node){
    if(vis[node]==2) return boxen[node].first;
    vis[node]=1;
    for(auto x: graph[node])
        if(vis[x]!=1) boxen[node].first+=1+dfs(x);
    vis[node]=2;
    return boxen[node].first;
}

int main()
{
    // Pesho's money is stored in boxen from 1 to N
    // he dropped all the keys needed to open the boxen in the boxen themselves
    // however, he has no keys at the beginning, so he must break boxen to obtain keys
    // what is the minimum amount of boxen that must be broken to open all the boxen
    // for this problem, lets redefine the term "outdegree" to signify the total number of nodes that are reachable from a given node
    // we must choose boxen to break in decreasing order of outdegree
    // this is similar to topological sorting

    ios_base::sync_with_stdio(0); cin.tie(NULL);  cout.tie(NULL);
    for(int t=0; t<2; t++){
        int n, x;
        cin >> n;
        memset(vis, 0, sizeof vis);
        boxen.resize(n);
        for(int i=0; i<n; i++){
            boxen[i].first=0; boxen[i].second=i;
            cin >> x; x--;
            if(x==i) continue;
            graph[x].pb(i); 
        }
        for(int i=0; i<n; i++) if(!vis[i]) dfs(i);
        sort(boxen.rbegin(), boxen.rend());
        memset(vis, 0, sizeof vis);
        int ans=0;
        for(int i=0; i<n; i++){ if(!vis[boxen[i].second]){dfs(boxen[i].second); ans++;} }
        for(int i=0; i<n; i++){ graph[i].clear(); }
        cout << ans << " ";
    }

    return 0;
}
