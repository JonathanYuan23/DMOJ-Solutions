#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

int main () {

  int N, S, T;
  cin >> N >> S >> T;

  int num{0};
  for (int i{0}; i<N; i++){
    int time;
    cin >> time;

    if(time*2>=S && time*2<=T){
      num++;
    }
  } cout << num;

  return 0;
}
