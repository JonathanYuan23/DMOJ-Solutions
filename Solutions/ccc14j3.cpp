#include <bits/stdc++.h>
#include <iostream>
#include<cmath>
using namespace std;

int main() {

int antonia=100, david=100;

int rounds;
cin >> rounds;

int count=0;
while(count<rounds){
  int a, d;
  cin >> a >> d;
  if(a<d){
    antonia-=d;
  }if(d<a){
    david-=a;
  }
  count++;
}

cout << antonia << endl << david;

return 0;
}
