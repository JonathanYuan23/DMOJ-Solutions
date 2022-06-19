#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;
int main () {

vector <int> nums;
int a, b, c, d;
cin >> a >> b >> c >> d;

nums.push_back(a);
nums.push_back(b);
nums.push_back(c);
nums.push_back(d);

if ((nums.at(0)==8 || nums.at(0)==9) && nums.at(1)==nums.at(2) && (nums.at(3)==8 || nums.at(3)==9)){
  cout << "ignore";
}

else {
  cout << "answer";
}

return 0;
}
