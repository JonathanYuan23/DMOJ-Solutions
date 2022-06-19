#include<bits/stdc++.h> 
using namespace std; 

int sheet[10][9], dp[10][9];  vector<pair<int, int>> cells;
map<pair<int, int>, vector<string>> dict;

bool visited[10][9], rec[10][9];

bool checkInt(string s){

  return all_of(s.begin(), s.end(), ::isdigit);

}

bool cycle(int i, int j){

  if(dict[{i, j}].size()==0)
    return false;

  visited[i][j] = true; rec[i][j] = true;

  for(int k{0}; k<dict[{i, j}].size(); k++){

    int n = dict[{i, j}][k][0]-'A', m = (dict[{i, j}][k][1]-'0')-1;

    if(!visited[n][m] && cycle(n, m))
      return true;
    else if(rec[n][m])
      return true;

  }

  rec[i][j] = false;
  return false;
}

int fillDP(int i, int j){

  if(dp[i][j]!=-1)
    return dp[i][j];

  if(dp[i][j]==-1){

    dp[i][j] = 0;

    for(int k{0}; k<dict[{i, j}].size(); k++){

      int n = dict[{i, j}][k][0]-'A', m = (dict[{i, j}][k][1]-'0')-1;
      dp[i][j] += fillDP(n, m);

    }

  }

  return dp[i][j];
}

bool fill(int i, int j){

  memset(visited, 0, sizeof visited); memset(rec, 0, sizeof rec);

  if(!cycle(i, j)){

    memset(visited, 0, sizeof visited);

    fillDP(i, j);

  }

  return true;
}

int main() 
{ 

  ios_base::sync_with_stdio(0);
  cin.tie(0);

  memset(sheet, -1, sizeof sheet);
  memset(dp, -1, sizeof dp);

  string s;
  for(int i{0}; i<10; i++){
    for(int j{0}; j<9; j++){

      cin >> s;

      if(!checkInt(s)){
        
        cells.push_back({i, j});

        int k=0;

        while(k<s.size()){

          dict[{i, j}].push_back(s.substr(k, 2));
          k+=3;

        }
        
      }
      else{

        sheet[i][j] = stoi(s);  dp[i][j] = stoi(s);

      }
    }
  }

  for(auto x: cells){

    if(dp[x.first][x.second]==-1){

      fill(x.first, x.second);

    }

  }

  for(int i{0}; i<10; i++){
    for(int j{0}; j<9; j++){
      
      if(dp[i][j]==-1)
        cout << "*" << " ";

      else
        cout << dp[i][j] << " ";

    } cout << "\n";
  }

	return 0; 
}
