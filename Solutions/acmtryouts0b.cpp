#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
#define INF 1<<30
using namespace std;
const int MAXN = 110;

int main(){

	ios_base::sync_with_stdio(0); cin.tie(NULL);  cout.tie(NULL);
  
  int t;  cin >> t;

  while(t--){

    int n;  cin >> n;

    string s1, s2, res="";  cin >> s1 >> s2;

    for(int i=0; i<n; i++){

      res+=s1[i]; res+=s2[i];

    }

    reverse(res.begin(), res.end());

    cout << res << "\n";

  }

  return 0;
}
