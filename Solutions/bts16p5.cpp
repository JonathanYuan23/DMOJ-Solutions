#include <bits/stdc++.h>
#define N 10001
using namespace std;

vector<int> graph[N];
int patchCherries[N], edges[N], dpCherries[N], dpWeight[N], n, c, k, globalCount{0};
bool visited[N];

int solveCherry(int v){

  int ans = patchCherries[v];

  for(auto x: graph[v])
    ans += solveCherry(x);

  return dpCherries[v] = ans;
}

int solveWeight(int v){

  int ans = edges[v];

  for(auto x: graph[v])
    ans += solveWeight(x);

  return dpWeight[v] = ans;
}

int main()
{

  cin >> n >> c >> k;

  for(int i{1}; i<=n; i++)
    cin >> patchCherries[i];

  int node, dest, weight;
  for(int i{0}; i<n-1; i++){

    cin >> node >> dest >> weight;

    edges[dest] = weight;
    graph[node].push_back(dest);

  }

  edges[1] = 0;

  solveCherry(1);
  solveWeight(1);

  for(int i{2}; i<=n; i++){
    if(dpCherries[i]>=c && dpWeight[i]<=k)
      globalCount++;
  }

  cout << globalCount << "\n";

  return 0;
}
