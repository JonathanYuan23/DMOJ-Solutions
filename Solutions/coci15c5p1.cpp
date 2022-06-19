#include <bits/stdc++.h>
using namespace std;

int main() {

  int n, m, max, l, d, x;
  cin >> l >> d >> x;

  for(int n=l; n<=d; n++){
    int sum=0, temp=n;
    while(temp!=0){
      sum+=temp%10;
      temp/=10;
    }
    if(sum==x){
      cout << n << endl;
      break;
    }
  }

  for (int m=l; m<=d; m++){
    int sum=0, temp=m;
    while(temp!=0){
      sum+=temp%10;
      temp/=10;
    }
    if(sum==x){
      max=m;
    }
  } 
  cout << max << endl;

  return 0;
}
