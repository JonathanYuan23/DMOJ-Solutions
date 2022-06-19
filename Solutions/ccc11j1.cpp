#include <bits/stdc++.h>

using namespace std;

int main() {
    
int a, e;
cin >> a >> e;


if (a >= 3 && e <= 4){
  cout << "TroyMartian" << endl;
if (a <= 6 && e != 1){
  cout << "VladSaturnian";
}
return 0;
}

if (a <= 6 && e >= 2){
  cout << "VladSaturnian" << endl;
if (a <= 2 && e != 1){
  cout << "GraemeMercurian";
}
return 0;
}

if (a <= 2 && e <= 3){
  cout << "GraemeMercurian";
  return 0;
}

if (a >= 6 && e >= 4){
  return 0;
}
    
    return 0;
}
