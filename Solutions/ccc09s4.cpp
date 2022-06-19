#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define MAXN 5005
using namespace std;
typedef pair<int, int> pii;

vector<pii> graph[MAXN];
int dist[MAXN], n, t, c, k, d, x, y;
bool visited[MAXN];

int main(){

    ios_base::sync_with_stdio(0); cin.tie(NULL);  cout.tie(NULL);

    cin >> n >> t;
    for(int i=0; i<t; i++){
        cin >> x >> y >> c;
        graph[x].push_back({y, c});
        graph[y].push_back({x, c});
    }

    cin >> k;
    vector<pii> p;
    for(int i=0; i<k; i++){
        cin >> x >> c; 
        p.push_back({x, c});
    }

    cin >> d;
    memset(dist, INF, sizeof dist);
    memset(visited, 0, sizeof visited);
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, d});
    dist[d]=0;

    while(!pq.empty()){
        int u=pq.top().second;
        pq.pop();
        if(visited[u])  continue;
        visited[u]=true;
        for(auto x: graph[u]){
            y=x.first;  c=x.second;
            if(dist[y]>dist[u]+c){
                dist[y]=dist[u]+c;
                if(!visited[y]){
                    pq.push({dist[y], y});
                }
            }
        }
    }

    int mn=INF;
    for(auto x: p) mn=min(mn, dist[x.first]+x.second);
    
    cout << mn << "\n";
    
    return 0;
}
