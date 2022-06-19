#include <bits/stdc++.h>
using namespace std;

int main()
{ 

int n, x, y, smallest{100000000};  cin >> n;

  while(n != 0){

    int i{1};

    while(i*i <= n){

      if(n%i==0){
        if((i*2 + (n/i)*2)<smallest){ 

          smallest = (i*2 + (n/i)*2);
          x = i;  y = n/i;
        }
      }

      i++;
    }

    cout << "Minimum perimeter is " << smallest <<  " with dimensions " << x << " x " << y << "\n";
    smallest = 100000000;
    cin >> n;
  }
    
  
  return 0;
}
