#include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

int main () {

  int spaces; cin >> spaces;

  vector <char> yesterday;
  vector <char> today;

  for(int i=0; i<spaces; i++)
  {
    char space; cin >> space;
    yesterday.push_back(space);
  }

  for(int i=0; i<spaces; i++)
  {
    char space; cin >> space;
    today.push_back(space);
  }

  int equal=0;
  for(int i=0; i<spaces; i++){
    if(yesterday[i]=='C' && today[i]=='C')
      equal++;
  }

  cout << equal;
  return 0;
}
