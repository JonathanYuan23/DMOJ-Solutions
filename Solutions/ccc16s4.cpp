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

const int MOD = 1000000007, INF = 0x3f3f3f3f, MX = 405, IMX = INT_MAX, IMN = INT_MIN;
const long long LLMX = LONG_LONG_MAX, LLMN = LONG_LONG_MIN;
const char nl = '\n';

// key observation, if all the balls in a range can be combined into a single ball, no matter how they are combined the final size is the same
int n, ans = 0, balls[MX], pre[MX];
bool dp[MX][MX];

int sum(int l, int r){
    return pre[r] - ((!l) ? 0 : pre[l-1]);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL);  cout.tie(NULL);
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> balls[i];
        pre[i] = pre[i-1] + balls[i];
        dp[i][i] = 1;
        ans = max(ans, balls[i]);
    }
    for(int i=2; i<=n; i++){
        if(balls[i] == balls[i-1]){
            dp[i-1][i] = 1;
            ans = max(ans, balls[i] + balls[i-1]);
        }
    }
    for(int len=3; len<=n; len++){
        for(int i=1, l, r; i + (len-1)<=n; i++){
            l = i, r = i + (len-1);
            for(int j=l; j<=r-1; j++){
                for(int k=j+1; k<=r; k++){
                    if(dp[l][j] && dp[k][r] && sum(l, j) == sum(k, r) && (j + 1 == k || dp[j+1][k-1])) dp[l][r] = 1;
                }
            }
            if(dp[l][r]) ans = max(ans, sum(l, r));
        }
    }
    cout << ans << nl;
    
    return 0;
}
