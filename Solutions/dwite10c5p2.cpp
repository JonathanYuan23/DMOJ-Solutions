#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
#define INF 1<<30
using namespace std;
const int MAXN = 65;

int main(){

	ios_base::sync_with_stdio(0); cin.tie(NULL);  cout.tie(NULL);
  
  for(int i=0; i<5; i++){

    int R, C, rooks, r, c;  cin >> R >> C >> rooks;

    set<int> rows, cols;

    for(int j=0; j<rooks; j++){

      cin >> r >> c;
      rows.insert(r); cols.insert(c);

    }

    int threaten = rows.size()*C + cols.size()*R - cols.size()*rows.size();

    cout << R*C - threaten << "\n";

  }
  

  return 0;
}
