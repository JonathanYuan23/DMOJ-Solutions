#include <bits/stdc++.h>
using namespace std;

bool travel(int a, int dist, int b){

  if(a<=dist && dist<=b)
    return true;
  else
    return false;

}

int main()
{

  vector<int> motels = {0, 990, 1010, 1970, 2030, 2940, 3060, 3930, 4060, 4970, 5030, 5990, 6010, 7000};

  int a, b, n, motel;  cin >> a >> b >> n;

  for(int i{0}; i<n; i++){cin >> motel; motels.push_back(motel);}

  sort(motels.begin(), motels.end());

  vector<long long> ways(motels.size(), 0);

  for(int i{0}; i<ways.size(); i++){

    if(travel(a, motels[i], b))
      ways[i] = 1;

  }

  for(int i{0}; i<ways.size(); i++){

    if(ways[i]>0){

      for(int j{i+1}; j<ways.size(); j++){

        if(travel(a, motels[j]-motels[i], b))
          ways[j]+=ways[i];

      }

    }

  }

  cout << ways[ways.size()-1] << "\n";

  return 0;
}
