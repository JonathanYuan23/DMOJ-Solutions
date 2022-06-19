#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
#define INF 1<<30
using namespace std;
const int MAXN=1005;

int T, N, M, P, Q, K, D;  string S;

map<string, multiset<pair<int, int>>> stores;

int main(){

  ios_base::sync_with_stdio(0); cin.tie(NULL);  cout.tie(NULL);

  cin >> T;

  for(int i=0; i<T; i++){

    cin >> N;

    for(int j=0; j<N; j++){

      cin >> M;

      for(int k=0; k<M; k++){

        cin >> S >> P >> Q;

        stores[S].insert({P, Q});

      }

    }

    int ans=0;  cin >> K;

    for(int j=0; j<K; j++){

      cin >> S >> D;

      for(auto x: stores[S]){

        if(D>=x.second){D-=x.second; ans+=x.second*x.first;}
        else{ans+=D*x.first; D=0;}

        if(D==0) break;
      }

    }

    cout << ans << "\n";
    stores.clear();
  }
  
  return 0;
}
