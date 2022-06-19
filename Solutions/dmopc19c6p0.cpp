#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main() {
int a, b, c;
cin >> a >> b >> c;

if(a<b+c){
  if(b<a+c){
    if(c<a+b){
      cout << "yes";
    }
  }
}if(a>=b+c || b>=a+c || c>=a+b){
  cout << "no";
}

return 0;
}
