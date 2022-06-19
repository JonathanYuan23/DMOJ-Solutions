#include <bits/stdc++.h>
#define N 2001
using namespace std;

bool connected[N][N]; int n, m, k, x, y;
vector<int> graph[N];

bool communicate = true;
void solve(){

  while(k--){

    cin >> x >> y;

    for(int i{0}; i<graph[x].size();  i++){

      if(connected[y][graph[x][i]]){

        communicate = false;
        return;

      }
      else{

        connected[y][graph[x][i]] = 1;
        connected[graph[x][i]][y] = 1;

      }

    }
    
    graph[x].push_back(y);

  }

}

int main()
{

  cin >> n >> m >> k;

  memset(connected, 0, sizeof connected);

  solve();

  if(communicate)
    cout << "YES\n";
  else
    cout << "NO\n";

  return 0;
}
