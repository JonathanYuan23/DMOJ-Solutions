#include <bits/stdc++.h>
using namespace std;

void combis(vector<int> &v, vector<int> &c, int state, int val1, int val2){

  if(state == 4){

    if(val1 <= 24)
      c.push_back(val1);

  }

  else if(state == 3){

    combis(v, c, state+1, val1 + val2, val2);
    combis(v, c, state+1, val1 - val2, val2);
    combis(v, c, state+1, val1 * val2, val2);   

    /*if(val1 % val2 == 0 && val2 != 0){

      combis(v, c, state+1, val1 / val2, val2);

    }*/

  }

  else if(state == 2){

    combis(v, c, state+1, val1, val2 + v[3]);
    combis(v, c, state+1, val1, val2 - v[3]);
    combis(v, c, state+1, val1, val2 * v[3]);

    if(val2 % v[3] == 0 && v[3] != 0)
      combis(v, c, state+1, val1, val2 / v[3]);

  }

  else if(state == 1){

    combis(v, c, state+1, val1 + v[1], val2);
    combis(v, c, state+1, val1 - v[1], val2);
    combis(v, c, state+1, val1 * v[1], val2);

    if(val1 % v[1] == 0 && v[1] != 0)
      combis(v, c, state+1, val1 / v[1], val2);

  }

}

void combi(vector<int> &vals, vector<int> &choices, int state, int val, int t, int m[]){

  if(state == 4){

    if(val <= 24)
      choices.push_back(val);

  }

  else{

      combi(vals, choices, state+1, val + vals[m[state]], t, m);
      combi(vals, choices, state+1, val - vals[m[state]], t, m);
      combi(vals, choices, state+1, val * vals[m[state]], t, m);

      if(val % vals[m[state]] == 0 && vals[m[state]] != 0)
        combi(vals, choices, state+1, val / vals[m[state]], t, m);

  }

}

void permute(vector<int> &s, vector<int> &c, int pos){

  if(pos >= s.size()){

    int m1[] = {0, 1, 2, 3};
    combi(s, c, 1, s[0], 1, m1);

    int m2[] = {0, 2, 0, 3};
    combi(s, c, 1, s[1], 2, m2);

    combis(s, c, 1, s[0], s[2]);

    int m3[] = {0, 3, 1, 0};
    combi(s, c, 1, s[2], 3, m3);

    int m4[] = {0, 2, 3, 0};
    combi(s, c, 1, s[1], 4, m4);
    return;

  }

  for(int i{pos}; i<s.size(); i++){

    swap(s[pos], s[i]);
    permute(s, c, pos+1);
    swap(s[pos], s[i]);

  }

}
 
int main()
{ 

  int n, v;   cin >> n;

  while(n--){

    vector<int> vals, choices;
    for(int i{0}; i<4; i++){

      cin >> v;   vals.push_back(v);

    }

    permute(vals, choices, 0);
    
    cout << *max_element(choices.begin(), choices.end()) << "\n";

  }
    
  return 0;
}
