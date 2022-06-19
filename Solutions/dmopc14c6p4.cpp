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

const int MOD = 1e9+7, INF = 0x3f3f3f3f, MX = 1e3+5, IMX = INT_MAX, IMN = INT_MIN;
const long long LLMX = LONG_LONG_MAX, LLMN = LONG_LONG_MIN;
const char nl = '\n';

// buses break separation
int N, M, H, b[MX], ans;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);  cout.tie(0);
    cin >> N >> M >> H;
    for(int i=0; i<N; i++) 
        cin >> b[i];
    for(int i=N-1, breaks; i>0; i--) {
        double b1 = b[i], b2 = b[i-1];
        if(b1 - b2 > H) {
            breaks = ceil((b1 - b2 - H) / M);
            ans += breaks, b[i - 1] += breaks * M;
        }
    }
    cout << ans << nl;
}

// 5 2 10
// 1
// 13
// 23
// 35
// 44
