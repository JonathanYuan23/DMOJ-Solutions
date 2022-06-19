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

const int MOD = 1000000007, INF = 0x3f3f3f3f, MX = 1000005, IMX = INT_MAX, IMN = INT_MIN;
const long long LLMX = LONG_LONG_MAX, LLMN = LONG_LONG_MIN;
const char nl = '\n';

ll n, q, h[MX], res[MX]; stack<int> s;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);  cout.tie(0);
    cin >> n >> q;
    for(int i=1; i<=n; i++){
        cin >> h[i];
        while(sz(s) && h[s.top()] > h[i]){
            ll j = s.top(), l; s.pop();
            l = (!sz(s) ? 0 : s.top());
            res[h[j]] += (1LL * i - j) * (j - l);
        }
        s.push(i);
    }
    while(sz(s)){
        ll j = s.top(), l; s.pop();
        l = (!sz(s) ? 0 : s.top());
        res[h[j]] += (1LL * n + 1 - j) * (j - l);
    }
    for(int i=1; i<MX; i++) res[i] += res[i-1];
    for(int tc=1, l, r; tc<=q; tc++){
        cin >> l >> r;
        cout << res[r] - res[l-1] << nl;
    }
    return 0;
}
