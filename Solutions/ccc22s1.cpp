#pragma GCC optimize "Ofast"
#include <bits/stdc++.h>
using namespace std;
#define frein freopen("input.txt", "r", stdin)

const int MX = 1e6+5;
const char nl = '\n';

int n, dp[MX];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);  cout.tie(NULL);
    cin >> n;
    dp[0] = 1;
    for(int i=4; i<=n; i++) dp[i] |= dp[i-4];
    int ans = 0;
    for(int i=0; i * 5 <= n; i++) {
        if(dp[n - i * 5]) ans++;
    }
    cout << ans << nl;
}
