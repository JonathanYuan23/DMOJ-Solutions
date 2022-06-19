#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
#define INF 0x3f3f3f3f
using namespace std;
typedef pair<int, pair<int, int>> piii;
const int MAXN=105;

vector<int> graph[MAXN];    vector<int> s;
int N, M, W, X, Y, movesLeft=1, dist[MAXN];
bool ants[MAXN];

int bfs(){
    memset(dist, -1, sizeof dist);
    memset(ants, 0, sizeof ants);
    queue<piii> q;
    q.push({0, {0, 1}});
    dist[1]=0;
    for(auto x: s){
        q.push({1, {0, x}});
        ants[x]=1;
    }
    while(!q.empty()){
        if(movesLeft==0){cout << "sacrifice bobhob314\n"; return -1;}
        int u=q.front().second.second, id=q.front().first, step=q.front().second.first;
        q.pop();
        if(id==1){
            for(auto x: graph[u]){
                if(step==3){
                    if(!ants[x]){
                        ants[x]=1;
                        q.push({1, {0, x}});
                    }
                } else {
                    q.push({1, {step+1, u}});
                }
            }
        } else {
            movesLeft--;
            if(u==N){cout << dist[u] << "\n"; return 0;}
            for(auto x: graph[u]){
                if(dist[x]==-1 && !ants[x]){
                    movesLeft++;
                    dist[x]=dist[u]+1;
                    q.push({0, {0, x}});
                }
            }
        }
    }
    cout << "sacrifice bobhob314\n";
    return -1;
}

int main() {

    ios_base::sync_with_stdio(0); cin.tie(NULL);  cout.tie(NULL);

    cin >> N >> M;
    for(int i=0; i<M; i++){
        cin >> X >> Y;
        graph[X].push_back(Y);
        graph[Y].push_back(X);
    }

    cin >> W;
    for(int i=0; i<W; i++){
        cin >> X;
        s.push_back(X);
    }

    bfs();

    return 0;
}
