#include <bits/stdc++.h>

using namespace std;

int main() {

int a;
int b;
int c;

cin >> a >> b >> c;

if (a + b + c == 180){
  if (a == 60 && b == 60 && c == 60){
    cout << "Equilateral";
  }
  if (a == b && b != c){
    cout << "Isosceles";
  }
  if (b == c && c != a){
    cout << "Isosceles";
  }
  if (a == c && c != b){
    cout << "Isosceles";
  }

  if (a != b && b != c && c != a){
    cout << "Scalene";
  }
}

else if (a + b + c != 180){
  cout << "Error";
}
    
    
    return 0;
}
