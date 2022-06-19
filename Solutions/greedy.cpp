#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize "Ofast"
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define fi first
#define se second
#define INF 0x3f3f3f3f
#define MAX 5000005
#define pb push_back
#define LSB(S) (S & (-S))
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<piii> viii;

vii fact;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL);  cout.tie(NULL);
    ll n, m;
    cin >> n >> m;
    fact.resize(n);
    for(int i=0; i<n; i++) cin >> fact[i].fi >> fact[i].se;
    sort(fact.begin(), fact.end());
    ll ans=0;
    for(int i=0; i<fact.size(); i++){
        if(m==0) break;
        if(m-fact[i].se>=0){
            ans+=fact[i].fi*fact[i].se;
            m-=fact[i].se;
        } else {
            ans+=fact[i].fi*m;
            m=0;
        }
    }
    cout << ans << "\n";
     
    return 0;
}
