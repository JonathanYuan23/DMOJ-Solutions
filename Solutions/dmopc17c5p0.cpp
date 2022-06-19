#include <bits/stdc++.h>
using namespace std;

int main() {
    
    int B, P;
    char x;
    
    cin >> B >> P >> x;
    
    if (B % P >= 0){
      if (x == 'N'){
        if (B - (P*5) < 0 && B - (P*2) >= 0)
          cout << "C";
        if (B - (P*5) >= 0)
          cout << "A";
      }
    
      if (x == 'Y'){
        if (B - (P*5) < 0 && B - (P*2) >= 0)
          cout << "D";
        if (B - (P*5) >= 0)
          cout << "B";
      }
    
      if (B < P*5 && B < P*2)
        cout << "NO PIZZA";
    
    }
    
    return 0;
}
