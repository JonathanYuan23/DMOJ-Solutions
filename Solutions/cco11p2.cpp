#pragma GCC optimize "Ofast"
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MOD 1000000009
#define fi first
#define se second
#define INF 0x3f3f3f3f
#define MAXN 1605
#define pb push_back
#define LSB(S) (S & (-S))
typedef pair<int, int> pii;
typedef pair<int, pair<int, int>> piii;

int S, N, M, A, B, dist[MAXN][3605], flag[MAXN][3605];
vector<piii> graph[MAXN];

void addEdge(int a, int b, int t, int h){
    int exposure=(!h)?0:t;
    graph[a].pb({b, {t, exposure}});
    graph[b].pb({a, {t, exposure}});
}

int dijkstra(){
    memset(dist, INF, sizeof dist);
    queue<piii> pq;
    pq.push({0, {0, 0}});
    dist[0][0] = 0;
    while(!pq.empty()){
        int d = pq.front().first, h = pq.front().second.first, v = pq.front().second.second;
        pq.pop();
        flag[v][h]=0;
        for(auto to: graph[v]){
            int dest = to.first, time = to.second.first, damage = to.second.second;
            if(h+damage>S) continue;
            if(dist[dest][h+damage] > dist[v][h]+time){
                dist[dest][h+damage] = dist[v][h]+time;
                if(!flag[dest][h+damage]){
                    flag[dest][h+damage]=1;
                    pq.push({dist[dest][h+damage], {h+damage, dest}});
                }
            }
        }
    }
    int ans=INF;
    for(int i=0; i<=3605; i++) ans=min(ans, dist[N-1][i]);
    return (ans==INF) ? -1 : ans;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL);  cout.tie(NULL);
    cin >> S >> N >> M;
    int a, b, t, h;
    for(int i=0; i<M; i++){
        cin >> a >> b >> t >> h;
        addEdge(a, b, t, h);
    }
    cout << dijkstra() << "\n";

    return 0;
}
