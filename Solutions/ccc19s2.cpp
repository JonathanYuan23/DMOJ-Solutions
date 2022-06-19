#include <bits/stdc++.h>
using namespace std;

int main() {

  int t; cin >> t;

  for (int i{0}; i<t; i++){
    int num; cin >> num;

    for(int i{2}; i<=num*2; i++){
      int b = (num-i)+num;

      bool prime{true}, prime2{true};
      for(int j{2}; j<=sqrt(i); j++){
        if(i%j==0){
          prime=false;
          break;
        }
      }for(int j{2}; j<=sqrt(b); j++){
        if(b%j==0){
          prime2=false;
          break;
        }
      }if(prime && prime2){
        cout << i << " " << b << endl;
        break;
      }
    }  
  } 
  return 0;
}
