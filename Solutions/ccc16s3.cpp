#include <bits/stdc++.h>
#define MOD 1000000007
#define ll long long
using namespace std;
const int MAXN = 100000, INF = 999999;

int N, M, V, mx_count=INT_MIN, leaf_count=0, dist[MAXN]; vector<int> graph[MAXN];
bool visited[MAXN], subtree[MAXN];

bool prune(int v, int prev){

  bool &ans = subtree[v];

  for(auto x: graph[v]){

    if(x!=prev)
      ans |= prune(x, v);

  }
  
  return ans;
}

void dfs(int node, int mx){

  visited[node] = 1;
  mx++;
  for(auto x: graph[node]){
    if(!visited[x] && subtree[x]){

      if(mx>mx_count){

        mx_count = mx;
        V = x;

      }

      dfs(x, mx);

    }
  }
}

int edges(int node, int prev){

  int count=0;

  for(auto x: graph[node]){

    if(subtree[x] && x!=prev)
      count += 1+edges(x, node);

  }

  return count;
}

int main(){
	
  ios_base::sync_with_stdio(0); cin.tie(NULL);  cout.tie(NULL);

  cin >> N >> M;

  int restaurant;
  for(int i=0; i<M; i++)
  {
    cin >> restaurant;
    subtree[restaurant] = 1;
  }

  int x, y;
  for(int i=0; i<N-1; i++){

    cin >> x >> y;
    graph[x].push_back(y);
    graph[y].push_back(x);

  }

  prune(restaurant, -1);

  memset(visited, 0, sizeof visited);
  dfs(restaurant, 0);

  memset(visited, 0, sizeof visited);
  dfs(V, 0);

  cout << (2*edges(restaurant, -1))-mx_count << "\n";

	return 0;
}
