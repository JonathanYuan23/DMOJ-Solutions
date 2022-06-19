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
#define pb push_back
#define LSB(x) (x & (-x))
#define sz(x) (int)(x.size())
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<pii, pii> piiii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<piii> viii;
typedef vector<piiii> viiii;

int N, M, B, Q, dist[MAX], vis[MAX];
vii adj[MAX];

void dijkstra(){
    memset(dist, INF, sizeof dist);
    memset(vis, 0, sizeof vis);
    priority_queue<pii, vii, greater<pii>> pq;
    pq.push({0, B});
    dist[B] = 0;
    while(!pq.empty()){
        int u = pq.top().se;
        pq.pop();
        if(vis[u]) continue;
        vis[u] = 1;
        for(auto to: adj[u]){
            if(dist[to.fi] > dist[u] + to.se){
                dist[to.fi] = dist[u] + to.se;
                if(!vis[to.fi]) pq.push({dist[to.fi], to.fi});
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL);  cout.tie(NULL);
    cin >> N >> M >> B >> Q;
    for(int i=0, a, b, c; i<M; i++){
        cin >> a >> b >> c;
        adj[a].pb({b, c});
        adj[b].pb({a, c});
    }
    dijkstra();
    for(int i=0, A; i<Q; i++){
        cin >> A;
        cout << ((dist[A] == INF) ? -1 : dist[A]) << '\n';
    }

    return 0;
}
