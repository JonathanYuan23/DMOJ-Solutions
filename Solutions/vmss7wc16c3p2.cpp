#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
#define INF 1<<30
#define LSOne(S) (S & (-S))
using namespace std;
const int MAXN=20005;

class uFind {                                 
private:
  vector<int> p, rank;                    
public:
  uFind(int N) {
    rank.assign(N, 0);
    p.assign(N, 0); 
    for (int i = 0; i < N; i++) p[i] = i; 
  }
  int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
  bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
  void unionSet(int i, int j) {
    if (!isSameSet(i, j)) { 
      int x = findSet(i), y = findSet(j);
      if (rank[x] > rank[y]) { p[y] = x; }
      else { 
        p[x] = y; 
        if (rank[x] == rank[y]) rank[y]++; 
      }                         
    }                           
  }
};

int N, M, A, B, X, Y;

int main(){

  ios_base::sync_with_stdio(0); cin.tie(NULL);  cout.tie(NULL);

  cin >> N >> M >> A >> B;
  uFind shahir(N+1);

  for(int i=0; i<M; i++){
    cin >> X >> Y;  shahir.unionSet(X, Y);
  }

  cout << ((shahir.isSameSet(A, B))?"GO SHAHIR!\n":"NO SHAHIR!\n");

  return 0;
}
