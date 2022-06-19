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
#define odd(x) (x % 2)

const int MOD = 1000000007, INF = 0x3f3f3f3f, MX = 20, IMX = INT_MAX, IMN = INT_MIN;
const long long LLMX = LONG_LONG_MAX, LLMN = LONG_LONG_MIN;
const char nl = '\n';

int n;
double bond[MX][MX], dp[1<<MX];

double rec(int i, int mask){
    if(i == n) return 1.0;
    if(dp[mask] != -1) return dp[mask];
    double ret = 0.0;
    for(int j=0; j<n; j++){
        if((mask & 1 << j) == 0) ret = max(ret, bond[i][j] * rec(i+1, mask | 1 << j));
    }
    return dp[mask] = ret;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL);  cout.tie(NULL); 
    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> bond[i][j];
            bond[i][j] /= 100.0;
        }
    }
    fill(dp, dp+(1<<MX),-1);
    cout << fixed << setprecision(9) << rec(0, 0)*100.0 << nl;
    
    return 0;
}
