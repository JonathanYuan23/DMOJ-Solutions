#include <bits/stdc++.h>
using namespace std;

unordered_map<char, char> dict;

void fill(){

  dict['A']='2';
  dict['B']='2';
  dict['C']='2';

  dict['D']='3';
  dict['E']='3';
  dict['F']='3';

  dict['G']='4';
  dict['H']='4';
  dict['I']='4';

  dict['J']='5';
  dict['K']='5';
  dict['L']='5';

  dict['M']='6';
  dict['N']='6';
  dict['O']='6';

  dict['P']='7';
  dict['Q']='7';
  dict['R']='7';
  dict['S']='7';

  dict['T']='8';
  dict['U']='8';
  dict['V']='8';

  dict['W']='9';
  dict['X']='9';
  dict['Y']='9';
  dict['Z']='9';
  

}

int main()
{

  fill();

  int n;  cin >> n;

  while(n--){

    string s, temp="", res="";  cin >> s;

    for(int i{0}; i<s.size(); i++)
      if(s[i]!='-')
        temp+=s[i];

    for(int i{0}; i<3;  i++){

      if(dict[temp[i]])
        res+=dict[temp[i]];
      else
        res+=temp[i];

    }

    res+='-';

    for(int i{3}; i<6;  i++){

      if(dict[temp[i]])
        res+=dict[temp[i]];
      else
        res+=temp[i];

    }

    res+='-';

    for(int i{6}; i<10;  i++){

      if(dict[temp[i]])
        res+=dict[temp[i]];
      else
        res+=temp[i];

    }

    cout << res << "\n";

  }

  return 0;
}
