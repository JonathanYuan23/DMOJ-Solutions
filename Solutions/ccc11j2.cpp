#include <bits/stdc++.h>
#include <iostream>
#include <cmath>
using namespace std;

int main() {
int h, max;
cin >> h >> max;

int t=1;
do{
  if(t==max){
    cout << "The balloon does not touch ground in the given time.";
    break;
  }int A=-6*pow(t, 4) + h*pow(t, 3) + 2*pow(t, 2) + t;
  if(A<=0){
    cout << "The balloon first touches ground at hour: " << endl << t ;
    break;
  }
  t++;
}while(t<=max);

return 0;
}
