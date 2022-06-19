#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize "Ofast"
#define frein freopen("input.txt", "r", stdin)
#define freout freopen("output.txt", "w", stdout)
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
// #define fi first
// #define se second
#define INF 0x3f3f3f3f
#define MAX 1005
#define IMX INT_MAX
#define IMN INT_MIN
#define LLMX LONG_LONG_MAX
#define LLMN LONG_LONG_MIN
#define pb push_back
#define pf push_front
#define LSB(x) (x & (-x))
#define sz(x) (ll)(x.size())
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<pii, pii> piiii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<piii> viii;
typedef vector<piiii> viiii;

#define v first
#define s second.first
#define t second.second

int n, dp[2][MAX], cur = 0, last = 0;
// v s t
piii p[MAX * 10];

bool compare(const piii &a, const piii &b){
    return a.t < b.t;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL);  cout.tie(NULL);
    cin >> n;
    for(int i=1; i<=n; i++) cin >> p[i].v >> p[i].s >> p[i].t;
    sort(p + 1, p + n + 1, compare);
    for(int i=1; i<=n; i++){
        for(int j=0; j<MAX; j++){
            dp[cur][j] = dp[last][j];
            if(j > p[i].t || j - p[i].s < 0) continue;
            dp[cur][j] = max(dp[cur][j], p[i].v + dp[last][j - p[i].s]);
        }
        last = cur;
        cur ^= 1;
    }
    int ans = -1;
    for(int i=0; i<=MAX; i++) ans = max(ans, dp[last][i]);
    cout << ans << '\n';

    return 0;
};
