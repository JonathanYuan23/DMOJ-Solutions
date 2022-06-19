#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100010;

int N, M, Q, C, dist[MAXN];
vector<int> graph[MAXN];

void bfs(){

  memset(dist, -1, sizeof dist);

  queue<int> q; q.push(C);
  dist[C]=0;

  while(!q.empty()){

    int v = q.front();  q.pop();

    for(auto x: graph[v]){

      if(dist[x]==-1){

        dist[x] = dist[v] + 1;
        q.push(x);

      }
    }
  }
}

int main()
{
    
  ios_base::sync_with_stdio(0); cin.tie(NULL);  cout.tie(NULL);
  cin >> N >> M >> Q >> C;

  int u, v;
  for(int i{0}; i<M; i++){

    cin >> u >> v;
    graph[u].push_back(v);  graph[v].push_back(u);

  }

  bfs();

  for(int i{0}; i<Q; i++){

    cin >> u >> v;

    if(dist[u]==-1 || dist[v]==-1)  cout << "This is a scam!\n";
    else  cout << dist[u] + dist[v] << "\n";

  }
   
  return 0;
}
