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
#define MAX 2005
#define IMX INT_MAX
#define IMN INT_MIN
#define LLMX LONG_LONG_MAX
#define LLMN LONG_LONG_MIN
#define pb push_back
#define pf push_front
#define LSB(x) (x & (-x))
#define sz(x) (int)(x.size())
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<pii, pii> piiii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<piii> viii;
typedef vector<piiii> viiii;

int T, N, M, G, vis[MAX], dis[MAX];
vii adj[MAX];
vi stores;

void dijkstra(){
    memset(dis, INF, sizeof dis);
    priority_queue<pii, vii, greater<pii>> pq;
    pq.push({0, 0});
    dis[0] = 0;
    while(!pq.empty()){
        int u = pq.top().se;
        pq.pop();
        if(vis[u]) continue;
        vis[u] = 1;
        for(auto to: adj[u]){
            if(dis[to.fi] > dis[u] + to.se){
                dis[to.fi] = dis[u] + to.se;
                if(!vis[to.fi]) pq.push({dis[to.fi], to.fi});
            }
        }
    }
    int res = 0;
    for(auto s: stores) if(dis[s] <= T) res++;
    cout << res << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL);  cout.tie(NULL);
    cin >> T >> N >> M >> G;
    stores.resize(G);
    for(int i=0; i<G; i++) cin >> stores[i];
    for(int i=0, u, v, c; i<M; i++){
        cin >> u >> v >> c;
        adj[u].pb({v, c});
    }
    dijkstra();
    return 0;
};
