#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main() {

  int jarQuarters, first, second, third; 
  cin >> jarQuarters >> first >> second >> third;

  int count{0};

  while(jarQuarters>0){
    jarQuarters--;
    count++;
    first++;
    if(first==35){
      jarQuarters+=30;
      first=0;
    }
    if (jarQuarters==0){
      break;
    }

    jarQuarters--;
    count++;
    second++;
    if(second==100){
      jarQuarters+=60;
      second=0;  
    } 
    if (jarQuarters==0){
      break;
    }

    jarQuarters--;
    count++;
    third++;
    if(third==10){
      jarQuarters+=9;
      third=0;
    }
    if (jarQuarters==0){
      break;
    }

  }

  cout << "Martha plays " << count << " times before going broke." << endl;

  return 0;
}
