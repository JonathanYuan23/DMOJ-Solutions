#include <bits/stdc++.h>
using namespace std;

int main()
{ 

  int N;  cin >> N;

  string words[3]{};

  bool prefix, suffix;
  while(N--){

    prefix = false; suffix = false;
    cin >> words[0] >> words[1] >> words[2];

    if(words[0].compare(0, words[1].size(), words[1])==0 || 
       words[0].compare(0, words[2].size(), words[2])==0 || 
       words[1].compare(0, words[0].size(), words[0])==0 ||
       words[1].compare(0, words[2].size(), words[2])==0 ||
       words[2].compare(0, words[0].size(), words[0])==0 ||
       words[2].compare(0, words[1].size(), words[1])==0)
        prefix = true;
    
    if(words[0].size()>=words[1].size()){
      if(words[0].compare(words[0].size()-words[1].size(), words[1].size(), words[1])==0)
        suffix = true;
    }
    if(words[0].size()>=words[2].size()){
      if(words[0].compare(words[0].size()-words[2].size(), words[2].size(), words[2])==0)
        suffix = true;
    }
    if(words[1].size()>=words[0].size()){
      if(words[1].compare(words[1].size()-words[0].size(), words[0].size(), words[0])==0)
        suffix = true;
    }
    if(words[1].size()>=words[2].size()){
      if(words[1].compare(words[1].size()-words[2].size(), words[2].size(), words[2])==0)
        suffix = true;
    }
    if(words[2].size()>=words[0].size()){
      if(words[2].compare(words[2].size()-words[0].size(), words[0].size(), words[0])==0)
        suffix = true;
    }
    if(words[2].size()>=words[1].size()){
      if(words[2].compare(words[2].size()-words[1].size(), words[1].size(), words[1])==0)
        suffix = true;
    }

    if(!suffix && !prefix)
      cout << "Yes\n";
    else
      cout << "No\n";
        
  }
  
  return 0;
}
