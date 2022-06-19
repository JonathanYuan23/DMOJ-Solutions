#include <bits/stdc++.h>
#include <iostream>
using namespace std;


int main() {

int small, medium, large;
cin>> small >> medium >> large;

int sum=(small)+(2*medium)+(3*large);

if(sum>=10){
  cout << "happy";
}

else if(sum<10){
  cout << "sad";
}

return 0;
}
