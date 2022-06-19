#include <bits/stdc++.h>

using namespace std;

int main() {

  int n;  cin >> n;
  int flowers[n][n], temp[n][n];

  int size = sizeof(flowers)/sizeof(flowers[0]);

  for(int i{0}; i<n; i++){
    for(int j{0}; j<n; j++)
      cin >> flowers[i][j];
  }
  
  for(int i{0}; i<n; i++){
    for(int j{0}; j<n; j++)
      temp[i][j] = flowers[i][j];
  }

  bool flag{true};

  while(flag){

    bool ascending{true};
    int smaller{flowers[0][0]};

    for(int i{1}; i<size; i++){
      if(flowers[i][0]<smaller){
        ascending=false;
        break;
      }else{
        smaller=flowers[i][0];
      }
    }

    for(int i{0}; i<size; i++){
      if(flowers[i][n-1]<=flowers[i][0])
        ascending=false;
    }

    if(ascending){
      for(int i{0}; i<size; i++){
        for(int j{0}; j<size; j++){
          cout << flowers[i][j] << " ";
        }
        cout << endl;
      }
      flag=false;
    }else{
      for(int i{0}; i<size; i++){
        for(int j{0}; j<size; j++){
          flowers[i][j] = temp[j][size-1-i];
        }
      }

      for(int i{0}; i<size; i++){
        for(int j{0}; j<size; j++){
          temp[i][j] = flowers[i][j];
        }
      }
    }
  }
  
  return 0;
}
