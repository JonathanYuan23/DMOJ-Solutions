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

const int MOD = 1000000007, INF = 0x3f3f3f3f, MX = 1e6 + 5, IMX = INT_MAX, IMN = INT_MIN;
const long long LLMX = LONG_LONG_MAX, LLMN = LONG_LONG_MIN;
const char nl = '\n';

int n, m, c, a[MX];
vi res; deque<int> dqmx, dqmn;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);  cout.tie(0);
    cin >> n >> m >> c;
    for(int i=1; i<=n; i++) {
        cin >> a[i];
        while(!dqmx.empty() && dqmx.front() <= i-m) dqmx.ppf();
        while(!dqmx.empty() && a[dqmx.back()] < a[i]) dqmx.ppb();
        dqmx.pb(i);
        while(!dqmn.empty() && dqmn.front() <= i-m) dqmn.ppf();
        while(!dqmn.empty() && a[dqmn.back()] > a[i]) dqmn.ppb();
        dqmn.pb(i);
        if(a[dqmx.front()] - a[dqmn.front()] <= c && i - m + 1 >= 1) res.pb(i - m + 1);
    }
    if(!sz(res)) cout << "NONE\n";
    else for(auto &x: res) cout << x << nl;
    return 0;
}
