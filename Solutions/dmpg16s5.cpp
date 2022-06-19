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

const int MOD = 1000000007, INF = 0x3f3f3f3f, MX = 200005, IMX = INT_MAX, IMN = INT_MIN;
const long long LLMX = LONG_LONG_MAX, LLMN = LONG_LONG_MIN;
const char nl = '\n';

int n, k;
ll psa[MX], ans = LLMN; deque<int> dq;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);  cout.tie(0);
    cin >> n >> k;
    for(int i=1; i<=n; i++) {
        cin >> psa[i];
        psa[i + n] = psa[i];
    }
    dq.pb(0);
    for(int i=1; i<=2*n; i++) {
        psa[i] += psa[i-1];
        while(sz(dq) && dq.front() < i - k) dq.ppf();
        while(sz(dq) && psa[dq.back()] > psa[i]) dq.ppb();
        dq.pb(i);
        ans = max(ans, psa[i] - psa[dq.front()]);
    }
    cout << ans << nl;
    return 0;
}
