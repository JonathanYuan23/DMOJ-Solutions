#include<bits/stdc++.h>
using namespace std;

vector<string> roads; vector<vector<int>> graph (26, vector<int>(26, 0));
vector<string> res;  vector<vector<int>> connected (26, vector<int>(26, 0));

int main()
{  

  string s; cin >> s; roads.push_back(s);

  graph[s[0]-'A'][s[1]-'A'] = 1;  graph[s[1]-'A'][s[0]-'A'] = 1;

  while(!(s[0]=='*'&&s[1]=='*')){

    cin >> s;

    if(s[0]!='*'){

      roads.push_back(s);
      graph[s[0]-'A'][s[1]-'A'] = 1;  graph[s[1]-'A'][s[0]-'A'] = 1;
      
    }

  }

  
  int count=0;
  for(int i{0}; i<roads.size(); i++){

    s=roads[i];
    graph[s[0]-'A'][s[1]-'A'] = 0;  graph[s[1]-'A'][s[0]-'A'] = 0;

    for(int i{0}; i<26; i++)
      for(int j{0}; j<26; j++)
        connected[i][j] = graph[i][j];
      
    for(int k{0}; k<26; k++){
      for(int i{0}; i<26; i++){
        for(int j{0}; j<26; j++){

          connected[i][j] = connected[i][j] || (connected[i][k]&&connected[k][j]);

        }
      }
    }

    if(connected[0][1] == 0){count++; res.push_back(s);}

    graph[s[0]-'A'][s[1]-'A'] = 1;  graph[s[1]-'A'][s[0]-'A'] = 1;

  }

  for(auto x: res)
    cout << x << "\n";

  cout << "There are " << count << " disconnecting roads.\n";

  return 0;
}
