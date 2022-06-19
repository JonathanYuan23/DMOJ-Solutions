#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
#define INF 1<<30
using namespace std;
const int MAXN = 100000;

int row[MAXN+5], col[MAXN+5], lft[MAXN*2+5], rit[MAXN*2+5];

int main(){

	ios_base::sync_with_stdio(0); cin.tie(NULL);  cout.tie(NULL);
  
  int n, k, r, c; cin >> n >> k;

  for(int i=1; i<=n; i++){

    cin >> r >> c;

    row[r]++; col[c]++; lft[r+c]++; rit[r+MAXN-c]++;

    if(row[r]==k || col[c]==k || lft[r+c]==k || rit[r+MAXN-c]==k){cout << i << "\n";  return 0;}

  }

  cout << -1 << "\n";
  
  return 0;
}
