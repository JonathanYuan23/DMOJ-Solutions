#include <bits/stdc++.h>

using namespace std;

int main() {
    
int n, count=0;

cin >> n;
while (n != 1){


  if (n%2 == 0){
    n = n/2;
    count++;
  }

  else if (n%2 != 0){
    n = n*3 + 1;
    count++;
  }

  else if (n == 1){
  cout << n;
  count++;
}

}

cout << count;
    
    
    
    
    
    return 0;
}
