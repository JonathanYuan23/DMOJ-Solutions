#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize "Ofast"
#define ll long long
#define ull unsigned long long
#define MOD 1e9+7
#define fi first
#define se second
#define INF 0x3f3f3f3f
#define MAX 200005
#define pb push_back
#define LSB(S) (S & (-S))
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<piii> viii;

vi fibo;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);  cout.tie(NULL);
    fibo.pb(0); fibo.pb(1); fibo.pb(1);
    for(;;){
        if(fibo.back()>1e9) break;
        fibo.pb(fibo[fibo.size()-1] + fibo[fibo.size()-2]);
    }
    for(int i=0; i<5; i++){
        int n, pos; 
        cin >> n;
        pos = lower_bound(fibo.begin(), fibo.end(), n) - fibo.begin();
        if(fibo[pos] == n) cout << n << '\n';
        else if(!pos) cout << ((fibo[pos+1]-n <= fibo[pos]-n) ? fibo[pos+1] : fibo[pos]) << "\n";
        else cout << ((fibo[pos]-n <= abs(fibo[pos-1]-n)) ? fibo[pos] : fibo[pos-1]) << "\n";
    }
    return 0;
}
