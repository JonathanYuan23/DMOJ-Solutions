#include <bits/stdc++.h>
using namespace std;

int main() {

  int x, m; cin >> x >> m;

  bool flag{true};
  for(int i{1}; i<m; i++){

    if((x * i)%m==1){
      cout << i << "\n";  flag = false;  break;
    }

  }

  if(flag)
    cout << "No such integer exists.\n";

  return 0;
}
