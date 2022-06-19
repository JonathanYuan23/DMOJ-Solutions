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

const int MOD = 1e9+7, INF = 0x3f3f3f3f, MX = 1e3, IMX = INT_MAX, IMN = INT_MIN;
const long long LLMX = LONG_LONG_MAX, LLMN = LONG_LONG_MIN;
const char nl = '\n';

int n, a[MX]; vii stacks;

bool insert(int size) {
    int pos = -1;
    for(int i=0; i<sz(stacks); i++) if(stacks[i].se > size && (pos == -1 || stacks[i].se - size < stacks[pos].se - size)) pos = i;
    if(pos == -1) return 0;
    stacks[pos].se = size;
    return 1;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);  cout.tie(0);
    cin >> n;
    for(int i=0; i<n; i++) cin >> a[i];
    sort(a, a+n, greater<int>());
    for(int i=0; i<n; i++) if(!insert(a[i])) stacks.eb(a[i], a[i]);
    ll ans = 0;
    for(auto &e: stacks) ans += e.fi;
    cout << ans << nl;
    return 0;
}
