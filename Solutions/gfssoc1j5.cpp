#include <bits/stdc++.h>
using namespace std;

int minDist[1001], n, m, t;
vector<int> graph[1001];

void bfs(int s, int d){

  memset(minDist, -1, sizeof minDist);

  queue<int> q; q.push(s);  minDist[s] = 0;

  while(!q.empty()){

    int v = q.front();  q.pop();

    for(auto x: graph[v]){

      if(minDist[x]==-1){

        minDist[x] = minDist[v] + t;
        q.push(x);

        if(x==d){cout << minDist[x] << "\n";  return;}

      }
    }
  }

  cout << "Not enough hallways!\n";
  return;
}

int main()
{

  ios_base::sync_with_stdio(0); cin.tie(NULL);  cout.tie(NULL);

  int a, b, q; cin >> n >> m >> t;

  for(int i{0}; i<m; i++){cin >> a >> b;  graph[a].push_back(b);}
  
  cin >> q;

  while(q--){cin >> a >> b; bfs(a, b);}

  return 0;
}
