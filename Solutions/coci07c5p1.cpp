#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main() {

  int one, two, three;
  cin >> one >> two >> three;

  if(one+two==three){
    cout << one << "+" << two << "=" << three;
  }else if(one-two==three){
    cout << one << "-" << two << "=" << three;
  }else if(one*two==three){
    cout << one << "*" << two << "=" << three;
  }else if(one/two==three){
    cout << one << "/" << two << "=" << three;
  }else if(one==two+three){
    cout << one << "=" << two << "+" << three;
  }else if(one==two+three){
    cout << one << "=" << two << "+" << three;
  }else if(one==two-three){
    cout << one << "=" << two << "-" << three;
  }else if(one==two*three){
    cout << one << "=" << two << "*" << three;
  }else if(one==two/three){
    cout << one << "=" << two << "/" << three;
  }

return 0;
}
