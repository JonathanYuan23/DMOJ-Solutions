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
#define MAX 5005
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

ll N, M, dis[MAX], dis2[MAX], vis[MAX];
vii adj[MAX];
viii edges;

void dijkstra(int start, ll res[]){
    for(int i=1; i<=N; i++){
        vis[i] = 0;
        res[i] = IMX;
    }
    priority_queue<pii, vii, greater<pii>> pq;
    pq.push({0, start});
    res[start] = 0;
    while(!pq.empty()){
        int u = pq.top().se;
        pq.pop();
        if(vis[u]) continue;
        vis[u] = 1;
        for(auto to: adj[u]){
            if(res[to.fi] > res[u] + to.se){
                res[to.fi] = res[u] + to.se;
                if(!vis[to.fi]) pq.push({res[to.fi], to.fi});
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL);  cout.tie(NULL);
    cin >> N >> M;
    for(int i=0, u, v, c; i<M; i++){
        cin >> u >> v >> c;
        adj[u].pb({v, c});
        adj[v].pb({u, c});
        edges.pb({c, {u, v}});
        edges.pb({c, {v, u}});
    }
    dijkstra(1, dis);
    dijkstra(N,  dis2);
    int best = IMX;
    for(auto E: edges){
        int u = E.se.fi, v = E.se.se, c = E.fi;
        int sbest = c + dis[u] + dis2[v];
        if(sbest > dis[N] && sbest < best) best = sbest;
    }
    cout << best << '\n';
    
    return 0;
}
