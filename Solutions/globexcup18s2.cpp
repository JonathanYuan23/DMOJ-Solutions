#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize "Ofast"
#define frein freopen("input.txt", "r", stdin)
#define freout freopen("output.txt", "w", stdout)
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define fi first
#define se second
#define INF 0x3f3f3f3f
#define MAX 1000005
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

bool comp(const pii &a, const pii &b){
    if(a.se == b.se) return a.fi > b.fi;
    return a.se < b.se;
}

ull n, m, k, ans = 0, score = 0;
vii tests;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL);  cout.tie(NULL);
    cin >> n >> m >> k;
    for(int i=0, x, y; i<n; i++){
        cin >> x >> y;
        tests.pb({x, y});
        ans += x;
    }
    if(ans >= n * k){
        cout << 0 << '\n';
        return 0;
    }
    sort(tests.begin(), tests.end(), comp);
    for(auto test: tests){
        ull add = min(m - test.fi, n * k - ans);
        score += add * test.se;
        ans += add;
        if(ans == n * k) break;
    }
    cout << score << '\n';
    return 0;
};
