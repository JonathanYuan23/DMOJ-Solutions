#include <bits/stdc++.h>
using namespace std;

int main() {

  int n, x, y;  cin >> n;

  int friends[10000];
  bool visited[10000];

  for(int i{0}; i<n; i++){
    cin >> x >> y;
    friends[x] = y;
  }

  cin >> x >> y;

  int distance;
  while(x != 0 && y != 0){

    for(int i{0}; i<10000; i++)
      visited[i] = false;

    distance = -1;
    while(!visited[x] && x != y){

      distance++;   visited[x] = true;
      x = friends[x];
    }

    if(x == y)
      cout << "Yes " << distance << endl;
    else
      cout << "No" << endl;

    cin >> x >> y;
  }

  return 0;
}
