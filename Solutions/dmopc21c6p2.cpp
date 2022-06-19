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

const int MOD = 1e9+7, INF = 0x3f3f3f3f, MX = 1e6+5, IMX = INT_MAX, IMN = INT_MIN;
const long long LLMX = LONG_LONG_MAX, LLMN = LONG_LONG_MIN;
const char nl = '\n';

int N, K, ans = 0;
string s; 
vii ranges;

bool comp(pii a, pii b) {
    return a.se - a.fi > b.se - b.fi;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);  cout.tie(0);
    cin >> N >> K >> s;

    char Type; int l, r;
    for(int i=0; i<N; i++) {
        if(!i) {
            Type = s[i];
            l = r = 0;
        }
        else {
            if(s[i] != Type) {
                if(s[l] == '0')
                    ranges.eb(l, r);
                Type = s[i];
                l = r = i;
            }   
            else {
                r++;
            }
        }
    }
    if(s[l] == '0')
        ranges.eb(l, r);
    sort(ranges.begin(), ranges.end(), comp);
    for(int i=0; i<min(K, sz(ranges)); i++) {
        ans += ranges[i].se - ranges[i].fi + 1;
    }
    cout << ans << nl;
}
