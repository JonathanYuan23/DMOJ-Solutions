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
#define ppf pop_front
#define LSB(x) (x & (-x))
#define sz(x) (int)(x.size())
#define ms(a, b) memset(a, b, sizeof a)

const int MOD = 1000000007, INF = 0x3f3f3f3f, MX = 300005, IMX = INT_MAX, IMN = INT_MIN;
const long long LLMX = LONG_LONG_MAX, LLMN = LONG_LONG_MIN;
const char nl = '\n';

ll n, ans, psamax[MX], psamin[MX];
vector<pair<ll, ll>> stkmax, stkmin;

void update(ll a, ll i){

    if(!sz(stkmax)) psamax[0] = a * i;
    else psamax[sz(stkmax)] = psamax[sz(stkmax) - 1] + a * (i - stkmax.back().se);

    if(!sz(stkmin)) psamin[0] = a * i;
    else psamin[sz(stkmin)] = psamin[sz(stkmin) - 1] + a * (i - stkmin.back().se);


}

void debug(){
    // DEBUG ======================================
    for(auto x: stkmax) cout << "(" << x.fi << ", " << x.se << ") ";
    cout << nl;
    for(auto x: stkmin) cout << "(" << x.fi << ", " << x.se << ") ";
    cout << nl;
    for(int i=0; i<sz(stkmax); i++) cout << psamax[i] << ' ';
    cout << nl;
    for(int i=0; i<sz(stkmin); i++) cout << psamin[i] << ' ';
    cout << nl << nl;
    // ============================================
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);  cout.tie(0);
    cin >> n;
    for(int i=1, a; i<=n; i++){
        cin >> a;
        while(sz(stkmax) && stkmax.back().fi <= a){
            psamax[sz(stkmax)-1] = 0;
            stkmax.ppb();
        }
        while(sz(stkmin) && stkmin.back().fi >= a){
            psamin[sz(stkmin)-1] = 0;
            stkmin.ppb();
        }
        update(a, i);
        stkmax.eb(a, i); stkmin.eb(a, i);
        ans += psamax[sz(stkmax)-1] - psamin[sz(stkmin)-1];
    }
    cout << ans << nl;
    return 0;
}
