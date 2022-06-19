#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
#define INF 1<<30
using namespace std;
const int MAXN = 15;

int sour[MAXN], bitter[MAXN], mx=INT_MAX, n;

void combi(int indx, vector<int> indxs){

  if(indx==n){

    if(indxs.empty()) return;

    int sourness=1, bitterness=0;

    for(auto x: indxs){

      sourness*=sour[x];  bitterness+=bitter[x];

    }

    if(abs(sourness-bitterness)<mx) mx = abs(sourness-bitterness);

    return;
  }

  combi(indx+1, indxs);
  indxs.push_back(indx);
  combi(indx+1, indxs);
  indxs.pop_back();

}

int main(){

  cin >> n;

  for(int i=0; i<n; i++) cin >> sour[i] >> bitter[i];

  vector<int> indxs;
  combi(0, indxs);

  cout << mx << "\n";

  return 0;
}
