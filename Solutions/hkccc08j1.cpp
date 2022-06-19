#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main () {

int casper;
cin >> casper;

int largest1=0;
for (int i=0; i<casper; i++){
  int weight, length;
  cin >> weight >> length;
  if(weight*length>largest1){
    largest1=weight*length;
  }
}

int natalie;
cin >> natalie;

int largest2=0;
for (int i=0; i<natalie; i++){
  int weight, length;
  cin >> weight >> length;
  if(weight*length>largest2){
    largest2=weight*length;
  }
}

if (largest1>largest2){
  cout << "Casper";
}else if (largest2 > largest1){
  cout << "Natalie";
}else if (largest1==largest2){
  cout << "Tie";
}

  return 0;
}
