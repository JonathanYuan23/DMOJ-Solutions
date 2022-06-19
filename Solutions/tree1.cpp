#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
#define INF 1<<30
using namespace std;
typedef vector<int> vi;
const int MAXN=4;

int arr[MAXN][MAXN];

class UnionFind {                                       
private:
  vi p, rank;
public:
  UnionFind(int N) {
    rank.assign(N, 0);
    p.assign(N, 0); 
    for (int i = 0; i < N; i++) p[i] = i; 
  }
  int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
  bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
  void unionSet(int i, int j) { 
    if (!isSameSet(i, j)) { 
      int x = findSet(i), y = findSet(j);
      if (rank[x] > rank[y]) { p[y] = x;}
      else { 
        p[x] = y;
        if (rank[x] == rank[y]) rank[y]++; 
      }              
    }         
  }
};

int main(){

  ios_base::sync_with_stdio(0); cin.tie(NULL);  cout.tie(NULL);

  UnionFind UF(4);

  int degree=0;
  for(int i=0; i<4; i++){ 
    for(int j=0; j<4; j++){
      cin >> arr[i][j]; if(arr[i][j]==1){degree++; UF.unionSet(i, j);}
    }
  }

  if(degree%2!=0 || degree/2!=3) cout << "No\n";
  else{
    for(int i=0; i<3; i++){
      for(int j=i+1; j<4; j++){
        if(!UF.isSameSet(i, j)){cout << "No\n"; return 0;}
      }
    }
    cout << "Yes\n";
  }

  return 0;
}
