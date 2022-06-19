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
#define MAX 200005
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

ll N, M, dis[MAX], vis[MAX];
vii adj[MAX];

void dijkstra(){
    for(int i=1; i<=N; i++) dis[i] = LLMN;
    priority_queue<pii> pq;
    pq.push({IMX, 1});
    dis[1] = IMX;
    while(!pq.empty()){
        int u = pq.top().se;
        pq.pop();
        if(vis[u]) continue;
        vis[u] = 1;
        for(auto to: adj[u]){
            if(dis[to.fi] < min(dis[u], (ll)to.se)){
                dis[to.fi] = min(dis[u], (ll)to.se);
                if(!vis[to.fi]) pq.push({dis[to.fi], to.fi});
            }
        }
    }
    for(int i=1; i<=N; i++){
        if(i == 1) cout << 0 << '\n';
        else cout << dis[i] << '\n';
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
    }
    dijkstra();
    return 0;
};
