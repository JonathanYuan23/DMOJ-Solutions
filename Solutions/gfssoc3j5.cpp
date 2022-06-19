#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
#define INF 1<<30
using namespace std;
const int MAXN=100;

int N, z, w, mn=INT_MAX, start=0;

unordered_map<int, int> costs;

int main(){

  cin >> N; vector<int> floors(N);

  for(int i=0; i<N; i++){cin >> floors[i] >> w; costs[floors[i]]=w; start+=w;}

  sort(floors.begin(), floors.end());

  do{

    int curr=101, stress=0, rem=start;

    for(int i=0; i<N; i++){
 
      stress+=rem*(abs(curr-floors[i])+1); 
      curr=floors[i]; 
      rem-=costs[floors[i]];

    }

    mn = min(mn, stress);

  } while(next_permutation(floors.begin(), floors.end()));

  cout << mn << "\n";

  return 0;
}
