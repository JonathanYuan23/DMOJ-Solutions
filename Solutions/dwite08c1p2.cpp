#include <bits/stdc++.h>
#include <iostream>
#include <string>

using namespace std;

int main() {
  string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

  for (int i{0}; i<5; i++){
    int num; cin >> num;
    char letter; cin >> letter;

    int a = (num/100000)%10;
    int b = (num/10000)%10;
    int c = (num/1000)%10;
    int d = (num/100)%10;
    int e = (num/10)%10;
    int f = num%10;

    int sum = a+b+c+d+e+f;

    int g = (sum/10)%10;
    int h = sum%10;

    int sum2 = g+h;
    char temp = alphabet.at(sum2-1);

    if(temp==letter){
      cout << "match" << endl;
    }else{
      cout << "error" << endl;
    }
  }
  return 0;
}
