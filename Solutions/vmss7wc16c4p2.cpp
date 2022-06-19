#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
#define INF 1<<30
using namespace std;
const int MAXN = 30;

vector<string> sets[MAXN];  int N, L;
set<string> res;

void combi(int indx, string str){

  if(indx==N || str.length()==L){

    res.insert(str);
    return;

  }

  for(auto x: sets[indx])
    combi(indx+1, str+x);

}

int main(){

	ios_base::sync_with_stdio(0); cin.tie(NULL);  cout.tie(NULL);
  
  cin >> N >> L;

  for(int i=0; i<N; i++){

    int m;  cin >> m;

    char c;
    for(int j=0; j<m; j++){

      cin >> c;
      string s(1, c);
      sets[i].push_back(s);

    }

    if(i>=1) sets[i].push_back("");

  }

  combi(0, "");

  for(auto x: res){

    cout << x << "\n";

  }
  
  return 0;
}
