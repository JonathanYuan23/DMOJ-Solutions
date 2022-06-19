#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main() {

  int n;
  cin >> n;

  int sum=0;
  for (int i=0; i<=n; i++){
    for (int j=i; j<=n; j++){
      sum+=i+j;
    }
  }

  cout << sum;

return 0;
}
