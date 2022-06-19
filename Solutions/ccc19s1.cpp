#include <bits/stdc++.h>

using namespace std;

int main() {

  vector <vector<int>> square = 
  {
    {1, 2},
    {3, 4}
  };

  string input;   cin >> input;

  for(int i{0}; i<input.size(); i++){
    if(input[i]=='H'){
      swap(square[0][0], square[1][0]);
      swap(square[0][1], square[1][1]);
    }if(input[i]=='V'){
      swap(square[0][0], square[0][1]);
      swap(square[1][0], square[1][1]);
    }
  }

  cout << square[0][0] << " " << square[0][1] << endl << square[1][0] << " " << square[1][1] << endl;
  
  return 0;
}
