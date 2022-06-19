#pragma GCC optimize "Ofast"
#include <bits/stdc++.h>
using namespace std; using pii = pair<int, int>;  using piii = pair<int, pii>;  using piiii = pair<pii, pii>;  using vi = vector<int>;  using vii = vector<pii>;  using viii = vector<piii>;  using viiii = vector<piiii>; using ll = long long; using ull = unsigned long long; 
#define frein freopen("input.txt", "r", stdin)
#define freout freopen("output.txt", "w", stdout)
#define fi first
#define se second
#define pb push_back
#define pf push_front
#define ppb pop_back
#define LSB(x) (x & (-x))
#define sz(x) (int)(x.size())

const int MOD = 1000000007, INF = 0x3f3f3f3f, MX = 2800, IMX = INT_MAX, IMN = INT_MIN;
const long long LLMX = LONG_LONG_MAX, LLMN = LONG_LONG_MIN;
const char nl = '\n';

int R, C, dp[105][MX];
vi valid, adj[MX];

int rec(int row, int i){
    if(row == R-1) return 0; if(dp[row][i] != -1) return dp[row][i];
    int ans = (!valid[i]) ? 0 : 1;
    for(auto &next: adj[i]) ans = (ans + rec(row + 1, next)) % MOD;
    return dp[row][i] = ans;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL);  cout.tie(NULL); 
    cin >> R >> C;
    for(int mask = 0; mask<1<<C-2; mask++) if(!(mask & mask<<1) && !(mask & mask<<2)) valid.pb(mask);
    for(int i=0, mask; i<sz(valid); i++){
        mask = valid[i];
        for(int j=0, mask2; j<sz(valid); j++){
            mask2 = valid[j] | valid[j]<<1 | valid[j]>>1;
            if(!(mask & mask2)) adj[i].pb(j);
        }
    }
    memset(dp, -1, sizeof dp);
    int ans = 0;
    for(int i=0; i<sz(valid); i++) ans = (ans + rec(0, i)) % MOD;
    cout << ans << nl;
    return 0;
}
