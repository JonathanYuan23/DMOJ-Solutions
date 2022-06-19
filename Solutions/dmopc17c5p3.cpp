#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
#define INF 1<<30
using namespace std;
const int MAXN=100005;

ll N, arr[MAXN];

ll _gcd(ll m, ll n) {
   if ((m % n) == 0)
      return n;
   else
      return gcd(n, m % n);
}

ll calc_gcd(){
    ll gcd=arr[0];
    for(int i=1; i<N; i++){
        gcd = _gcd(gcd, arr[i]);
    }
    return gcd;
}

int main() {

    ios_base::sync_with_stdio(0); cin.tie(NULL);  cout.tie(NULL);

    cin >> N;

    for(int i=0; i<N; i++) cin >> arr[i];

    ll gcd = calc_gcd();

    ll maxx=INT_MIN;

    while(gcd%2==0){
        maxx=max(maxx, (ll)2);
        gcd/=2;
    }

    for(ll i=3; i<=sqrt(gcd); i+=2){
        while(gcd%i==0){
            maxx=max(maxx, (ll)i);
            gcd/=i;
        }
    }

    if(gcd>2) maxx=max(maxx, gcd); 
    if(maxx==INT_MIN) cout << "DNE\n";
    else cout << maxx << "\n";

    return 0;
}
