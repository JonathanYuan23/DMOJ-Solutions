#include <bits/stdc++.h>
#include <iostream>

using namespace std;
int main() {
int n;
cin >> n;

int total=0;
for(int i=0; i<n; i++){
  int add;
  cin >> add;
  total+=add;
}

if(total<=200){
  cout << 200-total;
} else if(total>200){
  cout << "Over maximum capacity!";
}

return 0;
}
