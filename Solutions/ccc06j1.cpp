#include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

int main() {

  int burger, side, drink, dessert;
  cin >> burger >> side >> drink >> dessert;

  vector<vector<int>> foods = 
  {
        {461, 431, 420, 0}, 
        {100, 57, 70, 0}, 
        {130, 160, 118, 0}, 
        {167, 266, 75, 0}
  };

  int calories =
  {foods[0][burger-1]+foods[1][side-1]+foods[2][drink-1]+foods[3][dessert-1]};

  cout << "Your total Calorie count is " << calories << ".";

  return 0;
}
