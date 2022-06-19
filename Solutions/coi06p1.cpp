#pragma GCC optimize "Ofast"
#include <bits/stdc++.h>
using namespace std; using pii = pair<int, int>;  using piii = pair<int, pii>;  using piiii = pair<pii, pii>;  using vi = vector<int>;  using vii = vector<pii>;  using viii = vector<piii>;  using viiii = vector<piiii>; using ll = long long; using ull = unsigned long long; 
#define frein freopen("input.txt", "r", stdin)
#define freout freopen("output.txt", "w", stdout)
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define pf push_front
#define ppb pop_back
#define LSB(x) (x & (-x))
#define sz(x) (int)(x.size())
#define ms(a, b) memset(a, b, sizeof a)

const int MOD = 1000000007, INF = 0x3f3f3f3f, MX = 500005, IMX = INT_MAX, IMN = INT_MIN;
const long long LLMX = LONG_LONG_MAX, LLMN = LONG_LONG_MIN;
const char nl = '\n';

ll n, a[MX], res[MX]; stack<pair<ll, ll>> s;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);  cout.tie(0);
    cin >> n;
    for(int i=1; i<=n; i++) cin >> a[i];
    for(int i=n; i>=1; i--){
        ll j=0, repeated = 1;
        for(; !s.empty() && s.top().fi <= a[i]; s.pop()){
            j += s.top().se;
            if(s.top().fi == a[i]) repeated += s.top().se;
        }
        if(!s.empty()) j++;
        res[i] = j;
        s.push({a[i], repeated});
    }
    ll ans = 0;
    for(int i=1; i<=n; i++) ans += res[i];
    cout << ans << nl;
    return 0;
}
