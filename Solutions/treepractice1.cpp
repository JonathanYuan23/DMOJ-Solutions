//#pragma GCC optimize "Ofast"
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MOD 1000000009
#define p 31
#define INF 0x3f3f3f3f
#define MAXN 500005
#define pb push_back
#define LSB(S) (S & (-S))
typedef vector<int> vi;
typedef vector<vector<int>> vii;

int n, a, b, c, ans, v, dist[MAXN], dist2[MAXN];
vector<pair<int, int>> tree[MAXN];

void dfs(int node, int prev, int mx){
    dist[node]=mx;
    if(dist[node]>ans){
        ans=mx;  v=node;
    }
    for(auto x: tree[node]){
        if(x.first!=prev){
            dfs(x.first, node, mx+x.second);
        }
    }
}
void dfs2(int node, int prev, int mx){
    dist2[node]=mx;
    if(dist2[node]>ans){
        ans=mx;  v=node;
    }
    for(auto x: tree[node]){
        if(x.first!=prev){
            dfs2(x.first, node, mx+x.second);
        }
    }
}

int main()
{
    cin >> n;
    for(int i=1; i<n; i++){
        cin >> a >> b >> c;
        tree[a].pb({b, c});
        tree[b].pb({a, c});
    }
    ans=INT_MIN; dfs(1, -1, 0);
    ans=INT_MIN; dfs(v, -1, 0); dfs2(v, -1, 0);
    int rad=INT_MAX;
    for(int i=1; i<=n; i++) rad=min(rad, max(dist[i], dist2[i]));
    cout << ans << "\n" << rad << "\n";
    
    return 0;
}
