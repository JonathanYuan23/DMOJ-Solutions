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

const int MOD = 1000000007, INF = 0x3f3f3f3f, MX = 1e6+5, IMX = INT_MAX, IMN = INT_MIN;
const long long LLMX = LONG_LONG_MAX, LLMN = LONG_LONG_MIN;
const char nl = '\n';

int n; deque<int> dq; 
vi lo, high; 

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);  cout.tie(0);
    cin >> n; dq.resize(n);
    for(int i=0; i<n; i++) cin >> dq[i];
    sort(dq.begin(), dq.end());
    for(int i=0; i<n/2; i++) {
        lo.pb(dq.front());
        dq.ppf();
        high.pb(dq.back());
        dq.ppb();
    }
    for(int i=0; i<n/2; i++) {
        cout << lo[i] << ' ' << high[i];
        if(i < n/2-1 || (i == n/2-1 && sz(dq))) cout << ' ';
    }
    if(sz(dq)) cout << dq[0];
    cout << nl;
    for(int i=0; i<(n/2)*2; i++) cout << ((i%2==0) ? 'B' : 'S');
    if(sz(dq)) cout << 'E';
    cout << nl;
    return 0;
}
