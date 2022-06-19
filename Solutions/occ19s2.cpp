#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
#define INF 1<<30
using namespace std;

ll n;

int combi(ll num){

  if(num>n) return 0;

  int ans=1;

  ans += combi(num*10+2)+combi(num*10+3);

  return ans;
}

int main(){

  ios_base::sync_with_stdio(0); cin.tie(NULL);  cout.tie(NULL);
  
  cin >> n; 

  cout << combi(2) + combi(3) << "\n";

  return 0;
}
