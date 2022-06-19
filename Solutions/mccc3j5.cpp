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

const int MOD = 1e9+7, INF = 0x3f3f3f3f, MX = 20, IMX = INT_MAX, IMN = INT_MIN;
const long long LLMX = LONG_LONG_MAX, LLMN = LONG_LONG_MIN;
const char nl = '\n';

int N, M, r[MX][MX], ans = 0;

bool check(vi res) {
    for(int i=0; i<sz(res)-1; i++) 
        for(int j=i+1; j<sz(res); j++)
            if(r[res[i]][res[j]] == 1)
                return 0;
    return 1;
}

void recur(int i, vi res = {}) {
    if(sz(res)) 
        if(check(res))
            ans = max(ans, sz(res));
    if(i > N) return;
    res.pb(i); recur(i+1, res);
    res.ppb(); recur(i+1, res);
}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);  cout.tie(0);
    cin >> N >> M;
    for(int i=0, r1, r2; i<M; i++) {
        cin >> r1 >> r2;
        r[r1][r2] = r[r2][r1] = 1;
    }
    recur(1);
    cout << ans << nl;
    return 0;
}
