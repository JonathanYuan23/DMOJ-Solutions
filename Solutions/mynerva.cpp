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

int n, m, q, vis[MAX * 5];
vii adj[MAX * 5], white, black, res;
pii dis[MAX * 5];

void dijkstra(bool nx){
    for(int i=1; i<=n; i++) dis[i] = {IMX, IMX};
    memset(vis, 0, sizeof vis);
    dis[1] = {0, 0};
    priority_queue<pii, vii, greater<pii>> pq;
    // roads, island
    pq.push({0, 1});
    while(!pq.empty()){
        int roads = pq.top().fi, island = pq.top().se;
        pq.pop();
        if(vis[island]) continue;
        vis[island] = 1;
        for(auto to: adj[island]){
            if(dis[to.fi].fi > dis[island].fi + 1){
                dis[to.fi].fi = dis[island].fi + 1;
                dis[to.fi].se = dis[island].se + to.se;
                if(!vis[to.fi]) pq.push({dis[to.fi].fi, to.fi});
            }
            else if(dis[to.fi].fi == dis[island].fi + 1){
                if(!nx) dis[to.fi].se = min(dis[to.fi].se, dis[island].se + to.se);
                else dis[to.fi].se = max(dis[to.fi].se, dis[island].se + to.se);
                if(!vis[to.fi]) pq.push({dis[to.fi].fi, to.fi});
            }
        }
    }
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
    cin >> q;
    res.resize(q);
    string color;
    for(int i=0, v; i<q; i++){
        cin >> v >> color;
        if(color == "Black") black.pb({v, i});
        else white.pb({v, i});
    }
    dijkstra(0);
    for(auto v: black) res[v.se] = {dis[v.fi].fi, dis[v.fi].se};
    dijkstra(1);
    for(auto v: white) res[v.se] = {dis[v.fi].fi, dis[v.fi].se};
    for(auto v: res) cout << v.fi << ' ' << v.se << '\n';
    
    return 0;
};
