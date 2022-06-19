#include <bits/stdc++.h>

using namespace std;

int main() {
    
char a, b, c, d, e, f;
int win_count=0;
cin >> a >> b >> c >> d >> e >> f;

if (a == 'W'){
  win_count = win_count +1;
}if (b == 'W'){
  win_count = win_count+1;
}if (c == 'W'){
  win_count = win_count+1;
}if (d == 'W'){
  win_count = win_count+1;
}if (e == 'W'){
  win_count = win_count+1;
}if (f == 'W'){
  win_count = win_count+1;
}

if (win_count == 1 || win_count == 2){
  cout << "3";
}if (win_count == 3 || win_count ==4){
  cout << "2";
}if (win_count == 5 || win_count == 6){
  cout << "1";
}if (win_count == 0){
  cout << "-1";
}
    

    return 0;
}
