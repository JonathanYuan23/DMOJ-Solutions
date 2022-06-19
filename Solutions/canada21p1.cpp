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

const int MOD = 1000000007, INF = 0x3f3f3f3f, MX = 750005, IMX = INT_MAX, IMN = INT_MIN;
const long long LLMX = LONG_LONG_MAX, LLMN = LONG_LONG_MIN;
const char nl = '\n';

int T, N, r[MX], w[MX];
string s;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);  cout.tie(0);
    cin >> T;
    for(int tc=0; tc<T; tc++){
        cin >> N >> s;
        for(int i=1; i<=N; i++){
            r[i] = r[i-1], w[i] = w[i-1];
            s[i-1] == 'R' ? r[i]++ : w[i]++;
        }
        int ans = IMX, mn = IMX, l;
        for(int i=2; i<=N-1; i++){
            if(w[i-1] - r[i-1] < mn) mn = w[i-1] - r[i-1], l = i-1;
            ans = min(ans, (w[N] - w[i]) + (r[i] - r[l]) + w[l]);
        }
        cout << ans << nl;
        ms(r, 0); ms(w, 0);
    }
}
