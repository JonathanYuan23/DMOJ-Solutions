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

const int MOD = 1e9+7, INF = 0x3f3f3f3f, MX = 15, IMX = INT_MAX, IMN = INT_MIN;
const long long LLMX = LONG_LONG_MAX, LLMN = LONG_LONG_MIN;
const char nl = '\n';

int N, K, cAngles[MX];
bool dp[365], vis[MX];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);  cout.tie(0);
    cin >> N >> K;
    for(int i=0; i<N; i++) cin >> cAngles[i];
    dp[0] = 1;
    for(int i=0; i<=360*360; i++) { 
        for(int j=0, cur, pre; j<N; j++) {
            cur = i % 360;
            pre = (i - cAngles[j]) % 360;
            if(i - cAngles[j] >= 0) {
                dp[cur] |= dp[pre];
            }
        }
    }
    int query;
    while(K--) {
        cin >> query;
        cout << (dp[query] ? "YES\n" : "NO\n");
    }   
}
