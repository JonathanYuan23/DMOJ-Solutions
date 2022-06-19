#include <bits/stdc++.h>
using namespace std;

bool solve(string s){

  stack<char> B_S;  int i{0}; string chars = "AB";

  while(i<s.size()){

    if(chars.find(s[i])==string::npos)
      return false;

    if(s[i]=='A'){

      chars = "NS";
      i++;
      while(i<s.size()){

        if(i==s.size()-1 && !B_S.empty() && s[i]!='S')  return false;
        if(chars.find(s[i])==string::npos)  return false;
        if(i==s.size()-1 && B_S.empty())  return true;
        if(s[i]=='A'){chars = "SN"; i++;}
        else if(s[i]=='N'){

          if(i==s.size()-1 || s[i+1]=='S')  return false;
          else if(s[i+1]=='B'){chars = "AB"; i++;  break;}
          chars = "A"; i++;

        }
        else if(s[i]=='B'){chars="BA"; i++;  break;}
        else if(s[i]=='S'){

          if(B_S.empty()) return false;
          B_S.pop();  chars="BNS";  i++;  break;

        }
      }
    }

    else if(s[i]=='N'){chars = "AB";  i++;}
    else if(s[i]=='B'){B_S.push('B'); chars="BA"; i++;}
    else if(s[i]=='S'){

      if(B_S.empty()) return false;
      B_S.pop();  chars="BNS";  i++;

    }
  }
  return true;
}

int main()
{

  ios_base::sync_with_stdio(0); cin.tie(NULL);  cout.tie(NULL);

  string s; cin >> s;

  while(s!="X"){
    cout << ((solve(s)) ? "YES\n" : "NO\n");
    cin >> s; 
  }
  
  return 0;
}
