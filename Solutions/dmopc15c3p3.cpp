#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize "Ofast"
#define ll long long
#define MOD 1000000009
#define fi first
#define se second
#define INF 0x3f3f3f3f
#define MAXN 25
#define pb push_back
#define LSB(S) (S & (-S))
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<piii> viii;

vi graph[MAXN];
int N, M, C=0, dis[MAXN];

void cycles(int node, int par){
    for(auto to: graph[node]){
        if(to!=par){
            if(dis[to]!=-1){
                int cycleLen = dis[node]-dis[to]+1;
                if(cycleLen==6) C=1;
            } else {
                dis[to] = dis[node] + 1;
                cycles(to, node);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL);  cout.tie(NULL);
    cin >> N >> M;
    int u, v;
    for(int i=0; i<M; i++){
        cin >> u >> v;
        graph[u].pb(v);
        graph[v].pb(u);
    }
    memset(dis, -1, sizeof dis);
    dis[u]=0;
    cycles(u, -1);
    cout << ((C)?"YES":"NO") << "\n";
    
    return 0;
}
