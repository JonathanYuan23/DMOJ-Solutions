#include <bits/stdc++.h>
#define MOD 1000000007
#define ll long long
using namespace std;
const int MAXN = 500001, INF = 999999999;

vector<pair<int, int>> graph[MAXN], reversed[MAXN];  int N, M, D, a, b, k, dist[MAXN], rev[MAXN];  bool visited[MAXN];
vector<pair<pair<int, int>, int>> cindy;

void dijkstra(int u){

  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
  q.push({0, u});
  dist[u] = 0;

  while(!q.empty()){

    int v = q.top().second; q.pop();

    if(visited[v])
      continue;

    visited[v] = true;

    for(auto x: graph[v]){

      int node = x.first, weight=x.second;

      if(dist[node] > dist[v]+weight){

        dist[node] = dist[v] + weight;
        q.push({dist[node], node});

      }
    }
  }
}

void rev_dijkstra(int u){

  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
  q.push({0, u});
  rev[u] = 0;

  while(!q.empty()){

    int v = q.top().second; q.pop();

    if(visited[v])
      continue;

    visited[v] = true;

    for(auto x: reversed[v]){

      int node = x.first, weight=x.second;

      if(rev[node] > rev[v]+weight){

        rev[node] = rev[v] + weight;
        q.push({rev[node], node});

      }
    }
  }
}

int main(){
	
  ios_base::sync_with_stdio(0); cin.tie(NULL);  cout.tie(NULL);

  cin >> N >> M;

  for(int i=0; i<M; i++){

    cin >> a >> b >> k;
    graph[a].push_back({b, k});
    reversed[b].push_back({a, k});

  }

  cin >> D;

  for(int i=0; i<D; i++){

    cin >> a >> b >> k;
    cindy.push_back({{a, b}, k});

  }


  for(int i=1; i<=N; i++){dist[i] = INF;  rev[i] = INF;}

  memset(visited, 0, sizeof visited); dijkstra(1);
  memset(visited, 0, sizeof visited); rev_dijkstra(N);

  int shortest_with_cindy = dist[N];

  for(int i=0; i<cindy.size(); i++){

    int src = cindy[i].first.first, dest = cindy[i].first.second, weight = cindy[i].second;
    int mn = dist[src] + rev[dest] + weight;
    shortest_with_cindy = min(shortest_with_cindy, mn);

  }
	
  cout << ((shortest_with_cindy==INF) ? -1 : shortest_with_cindy) << "\n";

	return 0;
}
