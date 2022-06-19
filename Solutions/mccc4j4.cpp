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

const int MOD = 1e9+7, INF = 0x3f3f3f3f, MX = 2005, IMX = INT_MAX, IMN = INT_MIN;
const long long LLMX = LONG_LONG_MAX, LLMN = LONG_LONG_MIN;
const char nl = '\n';

int N, S, K;
pii countries[MX];
vii groups[MX];

bool comp(pii &a, pii &b) {
    if(a.se > b.se) return 1;
    if(a.se < b.se) return 0;
    return a.fi < b.fi;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);  cout.tie(0);
    cin >> N >> S;
    for(int i=0, c; i<N/S; i++) {
        for(int j=0; j<S; j++) {
            cin >> c;
            countries[c].fi = i;
        }
    }   
    char result;
    for(int i=0, a, b; i<(S-1)*N/2; i++) {
        cin >> a >> b >> result;
        if(result == 'W') countries[a].se += 3;
        else if(result == 'L') countries[b].se += 3;
        else {countries[a].se++, countries[b].se++;}
    }
    cin >> K;
    for(int i=1; i<=N; i++) {
        // push {country, score}
        groups[countries[i].fi].eb(i, countries[i].se);
    }
    for(int i=0; i<N/S; i++) {
        sort(groups[i].begin(), groups[i].end(), comp);
        cout << groups[i][K-1].fi << ((i<N/S-1) ? " " : "");
    }
    cout << nl;
    return 0;
}
