#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
#define INF 1<<30
using namespace std;
const int MAXN=1000000;

int psa[MAXN], N, K, Q, a, b, k;

int main(){

  ios_base::sync_with_stdio(0); cin.tie(NULL);  cout.tie(NULL);

  cin >> N >> K;

  for(int i=0; i<K; i++){

    cin >> k; psa[k]++;

  }

  for(int i=1; i<N; i++) psa[i]+=psa[i-1];
  
  cin >> Q;

  while(Q--){

    cin >> a >> b;

    cout << ((a==0)?psa[b]:psa[b]-psa[a-1]) << "\n";

  }
  
  return 0;
}
