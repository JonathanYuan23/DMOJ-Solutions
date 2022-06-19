#include<bits/stdc++.h> 
using namespace std; 
#define INF 0x3f3f3f3f

vector<int> graph[51];  int dist[51];  bool visited[51];
unordered_map<int, int> temp; set<int> res;

void fill(){

  graph[2].push_back(6);  graph[6].push_back(2);
  graph[1].push_back(6);  graph[6].push_back(1);
  graph[6].push_back(7);  graph[7].push_back(6);
  graph[6].push_back(3);  graph[3].push_back(6);
  graph[6].push_back(4);  graph[4].push_back(6);
  graph[6].push_back(5);  graph[5].push_back(6);
  graph[3].push_back(4);  graph[4].push_back(3);
  graph[3].push_back(5);  graph[5].push_back(3);
  graph[4].push_back(5);  graph[5].push_back(4);
  graph[3].push_back(15);  graph[15].push_back(3);
  graph[7].push_back(8);  graph[8].push_back(7);
  graph[8].push_back(9);  graph[9].push_back(8);
  graph[9].push_back(10);  graph[10].push_back(9);
  graph[10].push_back(11);  graph[11].push_back(10);
  graph[11].push_back(12);  graph[12].push_back(11);
  graph[12].push_back(9);  graph[9].push_back(12);
  graph[13].push_back(12);  graph[12].push_back(13);
  graph[13].push_back(15);  graph[15].push_back(13);
  graph[13].push_back(14);  graph[14].push_back(13);
  graph[16].push_back(17);  graph[17].push_back(16);
  graph[16].push_back(18);  graph[18].push_back(16);
  graph[18].push_back(17);  graph[17].push_back(18);

}

int friends(int node){

  int ans = 0;

  for(auto x: graph[node])
    temp[x] = 0;
  
  for(auto x: graph[node]){
    for(auto n: graph[x]){

      if(n!=node && temp.find(n)==temp.end() && find(res.begin(), res.end(), n)==res .end()){
        ans++;
        res.insert(n);
      }
    }
  }

  temp.clear();
  res.clear();
  return ans;
}

void dijkstra(int src, int dest){

  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

  pq.push({0, src});
  dist[src] = 0;

  while(!pq.empty()){

    int n = pq.top().second;  pq.pop();

    if(visited[n])
      continue;

    visited[n] = true;

    for(auto x: graph[n]){

      int v = x;
      
      if(dist[v] > dist[n]+1){

        dist[v] = dist[n]+1;
        pq.push({dist[v], v});

      }

    }

  }

  if(dist[dest]==INT_MAX)
    cout << "Not connected\n";
  else
    cout << dist[dest] << "\n";

}

int main() 
{ 

  fill();

  char select;  int node1, node2;

  cin >> select;

  while(select!='q'){

    if(select=='i'){

      cin >> node1 >> node2;
      graph[node1].push_back(node2);  graph[node2].push_back(node1);

    }

    else if(select=='d'){

      cin >> node1 >> node2;

      auto it1 = find(graph[node1].begin(), graph[node1].end(), node2);
      graph[node1].erase(it1);

      auto it2 = find(graph[node2].begin(), graph[node2].end(), node1);
      graph[node2].erase(it2);

    }

    else if(select=='n'){

      cin >> node1; cout << graph[node1].size() << "\n";

    }

    else if(select=='f'){

      memset(visited, 0, sizeof visited);

      cin >> node1;
      cout << friends(node1) << "\n";

    }

    else if(select=='s'){

      memset(visited, 0, sizeof visited);

      for(int i{0}; i<51; i++)
        dist[i] = INT_MAX;
      
      cin >> node1 >> node2;

      dijkstra(node1, node2);

    }

    cin >> select;

  }

	return 0; 
}
