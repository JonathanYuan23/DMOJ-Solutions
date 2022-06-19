#include <bits/stdc++.h>
using namespace std;
 
int main()
{
  int N, K, minT;  cin >> N >> K;

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

      minT = path[i-1] + abs(stones[i-1]-stones[i]);
      for(int j{1}; j<=K && i-j>=0; j++){

        path[i] = min((path[i-j] + abs(stones[i-j]-stones[i])), minT);

        minT = min(minT, (path[i-j] + abs(stones[i-j]-stones[i])));

      }
    }

    cout << path[N-1] << endl;
  }
    
  return 0;
}
