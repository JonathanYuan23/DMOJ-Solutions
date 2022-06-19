#include <bits/stdc++.h>
using namespace std;

int main() {

  int H, dot{1};  cin >> H;

  int spaces{H*2-2};

  for(int i{1}; i<=H; i++){

    if(i<H/2+1){

      for(int i{0}; i<dot; i++) cout << "*";

      for(int i{0}; i<spaces; i++) cout << " ";

      for(int i{0}; i<dot; i++) cout << "*";

      cout << "\n";

      dot+=2; spaces-=4;
      
    }

    else if(i == H/2+1){

      for(int i{0}; i<H*2; i++) cout << "*";
      cout << "\n";

      dot -= 2; spaces += 4;
      
    }

    if(i>H/2+1){

      for(int i{0}; i<dot; i++) cout << "*";

      for(int i{0}; i<spaces; i++) cout << " ";

      for(int i{0}; i<dot; i++) cout << "*";

      cout << "\n";

      dot-=2; spaces+=4;
      
    }
  }

  return 0;
}
