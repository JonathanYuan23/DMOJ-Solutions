#include <bits/stdc++.h>

using namespace std;

int main() {

  int square[4][4];

  for(int i{0}; i<4; i++){
    for(int j{0}; j<4; j++){
      cin >> square[i][j];
    }
  }

  int sum{0};
  for(int i{0}; i<4; i++)
    sum+=square[0][i];

  bool rowSum{true}, colSum{true};

  int tempSum{0};

  for(int i{1}; i<4; i++){
    tempSum=0;
    for(int j{0}; j<4; j++)
      tempSum+=square[i][j];
    
    if(tempSum!=sum)
      rowSum=false;
  }

  for(int i{0}; i<4; i++){
    tempSum=0;
    for(int j{0}; j<4; j++)
      tempSum+=square[j][i];
    
    if(tempSum!=sum)
      colSum=false;
  }

  if(rowSum && colSum)
    cout << "magic\n";
  else
    cout << "not magic\n";

  return 0;
}
