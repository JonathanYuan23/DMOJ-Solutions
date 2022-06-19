#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main() {

  int trout, pike, pickerel, points;
  cin >> trout >> pike >> pickerel >> points;

  int count{0};
  for (int i{0}; i<=100; i++){
    for (int j{0}; j<=100; j++){
      for (int k{0}; k<=100; k++){
        if((trout*i)+(pike*j)+(pickerel*k)<=points && (trout*i)+(pike*j)+(pickerel*k) != 0){

          cout << i << " Brown Trout, " << j << " Northern Pike, " << k << " Yellow Pickerel" << endl;
          count++;

        }
      }
    }
  }

  cout << "Number of ways to catch fish: " << count;

return 0;
}
