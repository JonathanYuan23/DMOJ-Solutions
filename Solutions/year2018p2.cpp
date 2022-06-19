#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


bool is_prime(int n) 
{ 
    if (n <= 1) 
        return false; 
  
    for (int i = 2; i*i <= n; i++) 
        if (n % i == 0) 
            return false; 
  
    return true; 
} 

int main() {
  int x,y, count = 0;
  cin >> x;
  for(int i = 0; i < x; i++) {
    
    cin >> y;
    if(is_prime(y)) {
      count++;
    }
  }
  cout << count << endl;
}
