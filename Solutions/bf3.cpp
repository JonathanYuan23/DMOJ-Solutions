#include <bits/stdc++.h>
#include <iostream>
#include <cmath>
using namespace std;

int main() {
int num;
cin >> num;
num=num;

if (num==1){
  cout << "2";
}else{
int count=0;
while(count==0){
  int count2=0;
  for(int i=2;i<=sqrt(num);++i){
    if(num%i==0){
      count2++;
    }
  }if(count2==0){
    count+=1;
  }else{
    num++;
  }
  
}cout << num;
}
return 0;
}
