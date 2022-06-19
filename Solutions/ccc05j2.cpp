#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int main () {

int range1, range2;
cin >> range1 >> range2;
int temp=range1;

int count=0;
while (range1<=range2){
  int temp2=1;
  int factors=0;
    while(temp2<=range1){
      if(range1%temp2==0){
        factors++;
      }
      temp2++;
    }
    if (factors==4){
      count++;
    }
  range1++;
}

cout << "The number of RSA numbers between " << temp << " and " << range2 << " is " << count;

return 0;
}
