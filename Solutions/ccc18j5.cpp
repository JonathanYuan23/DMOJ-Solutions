#include <bits/stdc++.h>
using namespace std;

vector<int> graph[10001]; int dist[10001];  bool visited[10001];

unordered_map<int, int> ending;

int mn = INT_MAX;
bool dijkstra(int v, int nodes){

  memset(visited, 0, sizeof visited);

  for(int i{0}; i<10001; i++)
    dist[i] = INT_MAX;

  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  pq.push({0, v});
  dist[v] = 1;

  while(!pq.empty()){

    int n = pq.top().second;  pq.pop();

    if(visited[n])
      continue;

    visited[n] = true;

    int node;
    for(auto x: graph[n]){

      node = x;

      if(dist[node] > dist[n]+1){

        dist[node] = dist[n]+1;
        pq.push({dist[node], node});

      }
    }
  }

  for(int i{1}; i<=nodes; i++){
    if(ending[i]){
      if(dist[i]<mn)
        mn = dist[i];
    }
  }
  
  for(int i{1}; i<=nodes; i++)
    if(dist[i]==INT_MAX)
      return false;

  return true;
}

int main()
{

  int n, m, v;  cin >> n;

  for(int i{1}; i<=n; i++){

    cin >> m;

    if(m==0)
      ending[i]++;

    else{

      while(m--){

        cin >> v;

        graph[i].push_back(v);

      }
    }
  }
  
  if(dijkstra(1, n)){

    cout << "Y\n" << mn << "\n";

  }
  else{

    cout << "N\n" << mn << "\n";

  }
  
  return 0;
}
