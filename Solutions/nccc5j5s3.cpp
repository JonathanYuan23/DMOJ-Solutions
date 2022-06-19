#pragma GCC optimize "Ofast"
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MOD 1000000009
#define p 31
#define INF 0x3f3f3f3f
#define MAXN 55
#define pb push_back
#define LSB(S) (S & (-S))
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vii;

int graph[MAXN][MAXN], vis[MAXN], N, M, u, v;
vector<pii> e;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL);  cout.tie(NULL);
    memset(graph, 0, sizeof graph);
    cin >> N >> M;
    for(int i=0; i<M; i++){
        cin >> u >> v;
        graph[u][v]=1;
        e.pb({u, v});
    }
    for(int i=0; i<e.size(); i++){
        memset(vis, 0, sizeof vis);
        u=e[i].first; v=e[i].second;
        graph[u][v]=0;
        vis[1]=1;
        queue<int> q;
        q.push(1);
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(int i=1; i<=N; i++){
                if(graph[node][i] && !vis[i]){
                    vis[i]=1;
                    q.push(i);
                }
            }
        }
        cout << ((vis[N])?"YES":"NO") << "\n";
        graph[u][v]=1;
    }

    return 0;
}
