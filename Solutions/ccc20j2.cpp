#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main() {

int total, infected, rate;
cin >> total >> infected >> rate;

int days=0, count=infected;
while(count<=total){
  infected=infected*rate;
  count+=infected;
  days++;
}

cout << days;
return 0;
}
