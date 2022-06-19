#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize "Ofast"
#define ll long long
#define ull unsigned long long
#define MOD 1e9+7
#define fi first
#define se second
#define INF 0x3f3f3f3f
#define MAX 1005
#define pb push_back
#define LSB(S) (S & (-S))
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<piii> viii;

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
      if (rank[x] > rank[y]) p[y] = x; 
      else { 
        p[x] = y; 
        if (rank[x] == rank[y]) rank[y]++; 
      }                          
    }                       
  }
};

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);  cout.tie(NULL);
    int N, Q;
    cin >> N >> Q;
    UnionFind ds(N);
    while(Q--){
        char c; int a, b;
        cin >> c >> a >> b;
        if(c=='A') ds.unionSet(--a, --b);
        else cout << ((ds.isSameSet(--a, --b))?"Y":"N") << "\n";
    }
    
    return 0;
}
