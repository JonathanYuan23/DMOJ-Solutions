#include <bits/stdc++.h>
using namespace std;

string consonants = "bcdfghjklmnpqrstvwxyz";

void ac(string word, int size){

  bool amer = true;

  if(size == 3){ cout << word << "\n";  return; }

  else{

    size_t pos = consonants.find(word[size-3]);

    if(word[size-1]=='r' && word[size-2]=='o' && pos != string::npos){
      word.insert(size-1, "u");
    }

    cout << word << "\n";   return;

  }
  
}

int main()
{ 

  string word;

  for(;;){

    cin >> word;

    if(word == "quit!")
      break;

    ac(word, word.size());

  }
  
  return 0;
}
