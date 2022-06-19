#include<bits/stdc++.h>

using namespace std;

int main () {

  vector<int> mushrooms;
  for(int i{0}; i<8; i++)
  {
    int slice;  cin >> slice;
    mushrooms.push_back(slice);
  }

  vector<int> mushroomsCombined;
  for(int i{0}; i<mushrooms.size()*2; i++)
  {
    if(i<mushrooms.size())
      mushroomsCombined.push_back(mushrooms[i]);
    else 
      mushroomsCombined.push_back(mushrooms[i-mushrooms.size()]);
  }

  int max{0};
  for(int i{0}; i<mushroomsCombined.size()-4; i++)
  {
    if(mushroomsCombined[i]+mushroomsCombined[i+1]+mushroomsCombined[i+2]+mushroomsCombined[i+3]>max)
    {
        max = mushroomsCombined[i]+mushroomsCombined[i+1]+mushroomsCombined[i+2]+mushroomsCombined[i+3];
    }
  }

  cout << endl <<max;

  return 0;
}
