#include <bits/stdc++.h>
using namespace std;
 
int main()
{
  int N, cost1, cost2;  cin >> N;

  int stones[N];

  for(int i{0}; i<N; i++)
    cin >> stones[i];

  int path[N];

  path[0] = 0;
  path[1] = abs(stones[0]-stones[1]);

  if(N == 2)
    cout << path[1] << endl;
  else{

    for(int i{2}; i<N; i++){
      path[i] = min((path[i-2] + abs(stones[i-2]-stones[i])), (path[i-1] + abs(stones[i-1]-stones[i])));
    }

    cout << path[N-1] << endl;
  }
    
  return 0;
}
