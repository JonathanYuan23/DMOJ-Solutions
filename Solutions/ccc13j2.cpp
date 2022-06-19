#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;
int main () {

string sign;
cin >> sign;

int count=0;

for (int i=0; i<sign.size(); i++){
  if(sign[i]!='I'&&sign[i]!='O'&&sign[i]!='S'&&sign[i]!='H'&&sign[i]!='Z'&&sign[i]!='X'&&sign[i]!='N'){
    count++;
  }
}

if (count==0){
  cout << "YES";
}

else if (count>0){
  cout << "NO";
}

return 0;
}
