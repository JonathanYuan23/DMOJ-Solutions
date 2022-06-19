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

const int MOD = 1e9+7, INF = 0x3f3f3f3f, MX = 35, IMX = INT_MAX, IMN = INT_MIN;
const long long LLMX = LONG_LONG_MAX, LLMN = LONG_LONG_MIN;
const char nl = '\n';

int N, ans, z;
priority_queue<int, vi, greater<int>> pqp, pqn;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);  cout.tie(0);
    cin >> N;
    for(int i=0, a; i<N; i++) {
        cin >> a;
        if(!a) z = 1;
        if(a > 0) pqp.push(a);
        if(a < 0) pqn.push(a);
    }
    // if both sets are empty, then zero is the only card
    if(!sz(pqp) && !sz(pqn)) {cout << 0 << nl; return 0;}

    // always use positive cards if available
    if(sz(pqp)) {
        ans = pqp.top(); pqp.pop();
        while(sz(pqp)) {ans *= pqp.top(); pqp.pop();}
    }

    // if there were no positive cards, and there is only one negative card
    if(!ans && sz(pqn) == 1) {
        ans = z ? 0 : pqn.top();
    }
    else {
        while(sz(pqn) > 1) {
            int f = pqn.top(); pqn.pop();
            int s = pqn.top(); pqn.pop();
            if(!ans) ans = f * s;
            else ans *= f * s;
        }
    }
    cout << ans << nl;
}
