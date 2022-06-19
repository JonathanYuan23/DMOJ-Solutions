#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int main () {

int num1, num2;
cin >> num1 >> num2;

int i=1, j=1;
int count = 0;
while (i<=num1){
j=1;

  while (j<=num2){
    if(i+j==10){
      count++;
    }
    j++;
  }
i++;
}

if (count==1){
  cout << "There is 1 way to get the sum 10.";
}else{
  cout << "There are " << count << " ways to get the sum 10.";
}

return 0;
}
