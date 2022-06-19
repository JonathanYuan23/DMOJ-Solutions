#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize "Ofast"
#define ll long long
#define fi first
#define se second
#define MOD 1000000009
#define prime 31
#define INF 0x3f3f3f3f
#define MAXN 10005
#define pb push_back
#define LSB(S) (S & (-S))
typedef pair<int, int> pii;
typedef pair<pair<int, int>, int> piii;
typedef vector<int> vi;
typedef vector<vector<int>> vii;

class UnionFind {                                             
private:
  vi p, rank;                   
public:
  UnionFind(int N) {
    rank.assign(N+1, 0);
    p.assign(N+1, 0); 
    for (int i = 0; i <= N; i++) p[i] = i; 
  }
  int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }

  bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }

  void unionSet(int i, int j) { 
    if (!isSameSet(i, j)) { 
      int x = findSet(i), y = findSet(j);
      if (rank[x] > rank[y]) p[y] = x;
      else { 
        p[x] = y;
        if (rank[x] == rank[y]) rank[y]++; 
      } 
    }                       
  }
};

int c, r, d, u, v, e, weights[MAXN];  
vector<piii> edges; vector<pii> mst[MAXN]; 

bool comp(piii a, piii b){
    return a.se > b.se;
}

void dfs(int node, int pre, int weight){
    weights[node]=weight;
    for(auto x: mst[node]){
        if(x.fi==pre) continue;
        dfs(x.fi, node, min(weight, x.se));
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL);  cout.tie(NULL);
    cin >> c >> r >> d;
    UnionFind trucking(c);
    for(int i=0; i<r; i++){
        cin >> u >> v >> e;
        edges.pb({{u, v}, e});
    }
    sort(edges.begin(), edges.end(), comp);
    for(auto E: edges){
        u=E.fi.fi; v=E.fi.se; c=E.se;
        if(trucking.findSet(u)!=trucking.findSet(v)){
            trucking.unionSet(u, v);
            mst[u].push_back({v, c});
            mst[v].push_back({u, c});
        }
    }
    dfs(1, -1, INF);
    int ans=INT_MAX;
    for(int i=0; i<d; i++){
        cin >> u;
        ans=min(ans, weights[u]);
    }
    cout << ans << "\n";

    return 0;
}
