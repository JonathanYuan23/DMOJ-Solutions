#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize "Ofast"
#define frein freopen("input.txt", "r", stdin)
#define freout freopen("output.txt", "w", stdout)
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define fi first
#define se second
#define INF 0x3f3f3f3f
#define MAX 10000005
#define pb push_back
#define LSB(x) (x & (-x))
#define sz(x) (int)(x.size())
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<pii, pii> piiii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<piii> viii;
typedef vector<piiii> viiii;

ll n, p, q, monkey[MAX], bit[MAX], bit2[MAX], psa[MAX];

ll query(int b) {                
    ll sum = 0; 
    for (; b; b -= LSB(b)) sum += bit[b];
    return sum; 
}

ll query2(int b) {                
    ll sum = 0; 
    for (; b; b -= LSB(b)) sum += bit2[b];
    return sum; 
}

void adjust(int k, int v) {               
    for (; k < n + 1; k += LSB(k)) bit[k] += v; 
}

void adjust2(int k, int v) {               
    for (; k < n + 1; k += LSB(k)) bit2[k] += v; 
}

void range_add(int l, int r, int val){
    adjust(l, val);
    adjust(r+1, -val);
}

void range_add2(int l, int r, int val){
    adjust2(l, val);
    adjust2(r+1, -val);
}

// n = 5, p = 1, q = 2
// 1 2 3 4 5

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL);  cout.tie(NULL);
    cin >> n >> p >> q;
    for(int i=1; i<=n; i++) cin >> monkey[i];
    for(int i=1; i<=n; i++){
        ll range = (n-(i-1)) * p / q, already = query(i), added = query2(i), days = psa[i-1];
        ll cur = ((monkey[i] - already) + added) % MOD;
        ll ans = (days + cur) % MOD;
        cout << ans << ' ';
        psa[i] = (cur + psa[i-1]) % MOD;
        range_add2(n - range + 1, n, cur * 1);
        range_add(i, n - range, cur);
    }
    
    return 0;
}
