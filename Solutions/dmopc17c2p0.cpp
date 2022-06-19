#include <bits/stdc++.h>
#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

int main() {

int x1, y1, x2, y2, x3, y3, D;
cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> D;

double length2, length3;

length2=sqrt(pow(x1-x3,2)+pow(y1-y3,2));
length3=sqrt(pow(x2-x3,2)+pow(y2-y3,2));

double abs2, abs3;
abs2 = abs(length2);
abs3 = abs(length3);

if(abs2<=D || abs3<=D){
  cout << "Yes";
}else if(abs2<=D && abs3<=D){
  cout << "Yes";
}else {
  cout << "No";
}

return 0;
}
