#include <bits/stdc++.h> 
using namespace std; 

int main() 
{ 

  int dist, n;  cin >> dist >> n;

  int clubs[n];

  for(int i{0}; i<n; i++){
    cin >> clubs[i];
  }

  vector<int> temp(dist+1, dist+1);
  temp[0] = 0;

  for(int i{1}; i<=dist; i++){
    for(int j{0}; j<n; j++){
      if(clubs[j] <= i){
        temp[i] = min(temp[i], temp[i-clubs[j]]+1);
      }
    }
  }

  if(temp[dist]>dist)
    cout << "Roberta acknowledges defeat." << endl;
  else
    cout << "Roberta wins in " << temp[dist] << " strokes." << endl;
    
  return 0; 
}
