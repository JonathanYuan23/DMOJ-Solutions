//#pragma GCC optimize "Ofast"
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

vector<pii> tree[MAXN];
int mxx=INT_MIN, sum=0, u, v, e, n;

void pre(int node, int par){
    for(auto x: tree[node]){
        if(x.first==par) continue;
        sum+=2*x.second;
        pre(x.first, node);
    }
}

void dfs(int node, int par, int cost){
    mxx=max(mxx, cost);
    for(auto x: tree[node]){
        if(x.first==par) continue;
        dfs(x.first, node, cost+x.second);
    }
}

int main()
{
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> u >> v >> e;
        tree[u].pb({v, e});
        tree[v].pb({u, e});
    }
    pre(0, -1);
    dfs(0, -1, 0);
    cout << sum-mxx << "\n";

    return 0;
}
