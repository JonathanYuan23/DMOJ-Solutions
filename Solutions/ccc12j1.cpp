#include <bits/stdc++.h>

using namespace std;

int main() {


int limit, speed;

cin >> limit >> speed;

if (speed <= limit){
  cout << "Congratulations, you are within the speed limit!";
}

if (speed > limit){
  if (speed >= limit+1 && speed <= limit+20){
    cout << "You are speeding and your fine is $100.";
  }
  if (speed >= limit+21 && speed <= limit+30){
    cout << "You are speeding and your fine is $270.";
  }
  if (speed >= limit+31){
    cout << "You are speeding and your fine is $500.";
  }
}
    
    return 0;
}
