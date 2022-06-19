#include<bits/stdc++.h>
using namespace std;

bool isCyclic(int i, vector<int> graph[], bool *visited, bool *rec){

    visited[i] = true;
    rec[i] = true;

    for(int j{0}; j<graph[i].size();  j++){

      if(!visited[graph[i][j]] && isCyclic(graph[i][j], graph, visited, rec))
        return true;
      else if(rec[graph[i][j]])
        return true;

    }


  rec[i] = false;
  return false;

}

bool cycle(int n, vector<int> graph[]){

  bool *visited = new bool[n];  bool *rec = new bool[n];

  for(int i{0}; i<n; i++){visited[i]=false; rec[i]=false;}

  for(int i{0}; i<n; i++)
    if(isCyclic(i, graph, visited, rec))
      return true;

  return false;
}
  
int main()
{

  int n, m, a, b; cin >> n >> m;

  vector<int> graph[n];

  for(int i{0}; i<m; i++){

    cin >> a >> b;

    graph[a-1].push_back(b-1);

  }

  if(cycle(n, graph))
    cout << "N\n";
  
  else
    cout << "Y\n";

  return 0;
}
