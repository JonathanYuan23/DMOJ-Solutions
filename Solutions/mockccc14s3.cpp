#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
#define INF 1<<30
using namespace std;
const int MAXN=100;

int R, C, N, c;

vector<vector<int>> stable(vector<vector<int>> arr){

  if(arr.size()<=1) return arr;

  vector<vector<int>> s, g, res_s, res_g, res;
  int pivot = arr[arr.size()-1][c];

  for(int i=0; i<arr.size(); i++){

    if(i!=arr.size()-1){

      if(arr[i][c]<pivot || arr[i][c]==pivot) s.push_back(arr[i]);
      else g.push_back(arr[i]);

    }

  }

  res_s = stable(s);  res_g = stable(g);

  for(auto x: res_s) res.push_back(x);
  res.push_back(arr[arr.size()-1]);
  for(auto x: res_g) res.push_back(x);

  return res;
}

void print(vector<vector<int>> arr){

  for(auto x: arr){
    for(auto n: x){
      cout << n << " ";
    } cout << "\n";
  }

}

int main(){

  ios_base::sync_with_stdio(0); cin.tie(NULL);  cout.tie(NULL);

  cin >> R >> C;

  vector<vector<int>> arr(R, vector<int>(C));

  for(int i=0; i<R; i++)
    for(int j=0; j<C; j++)
      cin >> arr[i][j];

  cin >> N;

  while(N--){

    cin >> c; c--;

    vector<vector<int>> sorted = stable(arr);

    arr=sorted;

  }

  print(arr);

  return 0;
}
