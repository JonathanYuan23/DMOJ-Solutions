#include <bits/stdc++.h>

using namespace std;

int main() {
    
int a, b, c;
cin >> a >> b >> c;

if (a < b && b < c){
  cout << b; 
}
if (a < c && c < b){
  cout << c;
}
if (b < c && c < a){
  cout << c;
}
if (b < a && a < c){
  cout << a;
}
if (c < a && a < b){
  cout << a;
}
if (c < b && b < a){
  cout << b;
}
    
    return 0;
}
