#include <bits/stdc++.h>
using namespace std;

unordered_map<char, int> shifts;

string alphab {"ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZ"};

int main()
{ 

  for(int i{0}; i<26; i++)
    shifts.insert(make_pair(alphab[i], i));  

  string keyword, message, encrypted{""}, newMessage{""};  
  cin >> keyword; 

  cin.ignore();

  getline(cin, message);

  for(int i{0}; i<message.length(); i++)
    if(isalpha(message[i]))
      newMessage+=message[i];

  int count{0};
  for(int i{0}; i<newMessage.length(); i++){

    if(count == keyword.length())
      count = 0;

    int found = alphab.find(newMessage[i]);

    found += shifts[keyword[count]];

    encrypted += alphab[found];
    
    count++;
  }

  cout << encrypted << "\n";
  
  return 0;
}
