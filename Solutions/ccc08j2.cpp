#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

vector <char> mp3= {'A', 'B', 'C', 'D', 'E'};

int command, repeat;
do {
  cin >> command >> repeat;

  int count=0;
  while(count<repeat){
    if(command==1){
      int first=mp3.at(0);
      mp3.erase(remove(mp3.begin(), mp3.end(), first));
      mp3.push_back(first);
    }if(command==2){
      int last=mp3.at(4);
      mp3.erase(remove(mp3.begin(), mp3.end(), last));
      mp3.insert(mp3.begin(), last);
    }if(command==3){
      int temp=mp3.at(0);
      mp3.at(0)=mp3.at(1);
      mp3.at(1)=temp;
    }if(command==4){
      break;
    }
    count++;
  }
}while(command!=4);

for (auto n: mp3){
  cout << n << " ";
}

return 0;
}
