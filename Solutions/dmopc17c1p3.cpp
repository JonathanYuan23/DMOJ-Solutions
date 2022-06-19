#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize "Ofast"
#define frein freopen("input.txt", "r", stdin)
#define freout freopen("output.txt", "w", stdout)
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define fi first
#define se second
#define INF 0x3f3f3f3f
#define MAX 100005
#define IMX INT_MAX
#define IMN INT_MIN
#define LLMX LONG_LONG_MAX
#define LLMN LONG_LONG_MIN
#define pb push_back
#define pf push_front
#define LSB(x) (x & (-x))
#define sz(x) (ll)(x.size())
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<pii, pii> piiii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<piii> viii;
typedef vector<piiii> viiii;

int n, m, vis[MAX];
vii adj[MAX];
pii dis[MAX];

void dijkstra(){
    for(int i=1; i<=n; i++) dis[i] = {INF, INF};
    dis[1] = {0, 0};
    priority_queue<piii, viii, greater<piii>> pq;
    // danger roads, dist, city
    pq.push({0, {0, 1}});
    while(!pq.empty()){
        int danger = pq.top().fi, dist = pq.top().se.fi, city = pq.top().se.se;
        pq.pop();
        if(vis[city]) continue;
        vis[city] = 1;
        for(auto to: adj[city]){
            if(dis[to.fi].fi > dis[city].fi + to.se){
                dis[to.fi].fi = dis[city].fi + to.se;
                dis[to.fi].se = dis[city].se + 1;
                if(!vis[to.fi]) pq.push({dis[to.fi].fi, {dis[to.fi].se, to.fi}});
            }
            else if(dis[to.fi].fi == dis[city].fi + to.se){
                dis[to.fi].se = min(dis[to.fi].se, dis[city].se + 1);
                if(!vis[to.fi]) pq.push({dis[to.fi].fi, {dis[to.fi].se, to.fi}});
            }
        }
    }
    if(dis[n].fi == INF) cout << -1 << '\n';
    else cout << dis[n].fi << ' ' << dis[n].se << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL);  cout.tie(NULL);
    cin >> n >> m;
    for(int i=0, u, v, c; i<m; i++){
        cin >> u >> v >> c;
        adj[u].pb({v, c});
        adj[v].pb({u, c});
    }
    dijkstra();
    return 0;
};
