#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main() {
int times;
cin >> times;

int count=0;
while(count<times){
  int year, month, day;
  cin >> year >> month >> day;

  if(year<1989){
    cout << "Yes" << endl;
  }if(year>1989){
    cout << "No" << endl;
  }if(year==1989){
    if(month==2 && day<=27){
      cout << "Yes" << endl;
    }else if(month<2){
      cout << "Yes" << endl;
    } else{
      cout << "No" << endl;
    }
  }
  count++;
}
return 0;
}
