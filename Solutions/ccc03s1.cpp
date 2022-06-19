#include <bits/stdc++.h>
#include <iostream>
#include<string>
using namespace std;


int main() {

int sum=1, n;

while(sum<100){
  cin>>n;

if(n!=0){
  sum = sum+n;}

if(n==0){
sum=0;
}

if(sum==9){
sum=34;
cout << "You are now on square 34" << endl;
}
  else if(sum==40){
    sum=64;
    cout << "You are now on square 64" << endl;
  }
    else if(sum==67){
      sum=86;
      cout << "You are now on square 86" << endl;
    }
      else if(sum==54){
        sum=19;
        cout << "You are now on square 19" << endl;
      }
        else if(sum==90){
        sum=48;
        cout << "You are now on square 48" << endl;
      }
          else if(sum==99){
        sum=77;
        cout << "You are now on square 77" << endl;
      }
      else if(sum<100 && sum>0){
      cout << "You are now on square "<< sum << endl;
}

if(sum>100){
  sum=sum-n;
  cout << "You are now on square " << sum << endl;
}

if(n==0){
  
  cout <<"You Quit!" << endl;
  break;
}

if(sum==100){
  cout << "You are now on square " << sum << endl;
  cout << "You Win!" << endl;
}

}

return 0;
}
