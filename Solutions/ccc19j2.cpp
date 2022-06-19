#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;
 
int main () {

int repeat; cin >> repeat;

for (int i{0}; i<repeat; i++){
  int n; char symbol;
  cin >> n >> symbol;
  for(int j{0}; j<n; j++){
    cout << symbol;
  }
  cout << endl;
}

return 0;
}
