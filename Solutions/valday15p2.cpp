#include <bits/stdc++.h>

using namespace std;

int main() {

  int C, M; cin >> C >> M;

  int weight[C], value[C];

  for(int i{0}; i<C; i++){
    cin >> value[i] >> weight[i];
  }

  int woo[C+1][M+1];

  for(int i{0}; i<=C; i++){
    for(int j{0}; j<=M; j++){
      if(i==0 || j==0){
        woo[i][j] = 0;
      }else if(weight[i-1] <= j){
        woo[i][j] = max(value[i-1]+woo[i-1][j-weight[i-1]], woo[i-1][j]);
      }else{
        woo[i][j] = woo[i-1][j];
      }
    }
  }

  cout << woo[C][M] << endl;

  return 0;
}
