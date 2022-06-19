#include<bits/stdc++.h>
using namespace std;

string s, t;
unordered_map<string, char> dict;

string build(int i, int l){

  return s.substr(i, l) + t.substr(i, l);

}

string solve(int index, string res){

  if(index==s.size())
    return res;

  if(index>s.size())
    return "";

  string temp1="", temp2="", output1="", output2="";

  if(index+1<s.size())
    temp1 = build(index, 2);

  if(index+2<s.size())
    temp2 = build(index, 3);

  if(dict[temp1])
    output1 = solve(index+2, res+dict[temp1]);

  if(dict[temp2])
    output2 = solve(index+3, res+dict[temp2]);

  if(output1!="" && output2=="")
    return output1;

  else if(output2!="" && output1=="")
    return output2;

  else
    return output1;

}

int main()
{

  dict.insert({"x.xx", 'A'}); //A
  dict.insert({"xxxx", 'B'}); //B
  dict.insert({"x.xxxx", 'C'}); //C
  dict.insert({"xx.x", 'D'});  //D
  dict.insert({"xxx.xx", 'E'}); //E

  for(int i{0}; i<5; i++){

    cin >> s >> t;

    string res = "";
    
    cout << solve(0, res) << "\n";

  }

  return 0;
}
