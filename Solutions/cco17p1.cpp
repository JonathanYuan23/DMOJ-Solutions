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
#define LSB(x) (x & (-x))
#define sz(x) (int)(x.size())
#define ms(a, b) memset(a, b, sizeof a)

const int MOD = 1000000007, INF = 0x3f3f3f3f, MX = 100005, IMX = INT_MAX, IMN = INT_MIN;
const long long LLMX = LONG_LONG_MAX, LLMN = LONG_LONG_MIN;
const char nl = '\n';

int k, n = 1, trails;
vii edgelist;

int bs(){
    int lo = 2, high = 4500, ret = 2;
    while(lo <= high){
        int mid = (lo + high) / 2;
        if(trails + mid * (mid - 1) / 2 <= k){ret = max(ret, mid); lo = mid + 1;}
        else high = mid - 1;
    }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL);  cout.tie(NULL); 
    cin >> k;
    for(;;){
        if(trails == k) break;
        int component = bs();
        for(int i=n+1; i<=n+component-1; i++) edgelist.eb(i, i-1);
        edgelist.eb(n, n+component-1);
        if(n > 1) edgelist.eb(n, n-1);
        trails += component * (component - 1) / 2, n += component;
    }
    assert(n-1 <= 5000 && sz(edgelist) <= 5000);
    cout << (n == 1 ? 1 : n-1) << ' ' << sz(edgelist) << nl;
    for(auto &edge: edgelist) cout << edge.fi << ' ' << edge.se << nl;
    return 0;
}
