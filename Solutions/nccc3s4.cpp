#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
#define INF 1<<30
#define LSOne(S) (S & (-S))
using namespace std;
const int MAXN=10005;

ll arr[MAXN];

int main(){

  ios_base::sync_with_stdio(0); cin.tie(NULL);  cout.tie(NULL);

  ll N, sum=0, mx=INT_MIN; cin >> N;

  for(int i=0; i<N; i++){cin >> arr[i]; sum+=arr[i]; mx=max(mx, arr[i]);}

  ll lsum=0;
  for(int i=0; i<N; i++){if(arr[i]!=mx) lsum+=arr[i];}

  cout << ((sum%2!=0 || lsum<mx)?"NO\n":"YES\n");

  return 0;
}
