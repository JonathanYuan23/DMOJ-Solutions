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

/*
 ai * (x - Li)^2 + bi * (x - Li) + ci

 = a * (x^2 - 2 * L * x + L^2) + b * (x - L) + c

 = a * x^2 - 2 * L * a * x + a * L^2 + b * x - b * L + c

 = a * x^2 + (-2 * L * a + b) * x + (a * L^2 - b * L + c)

 x is the current index being considered
 group the quadratic function into three terms, a quadratic term, linear term and constant term based on x
 then do updates with the coefficient of x in each term
*/
ll N, T, d2[MX], d1[MX], d0[MX];
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);  cout.tie(0);
    cin >> N >> T;
    for(int i=1, L, R, a, b, c; i<=N; i++) {
        cin >> L >> R >> a >> b >> c;
        // quadratic term
        d2[L] += a; d2[R+1] -= a;
        // linear term
        ll val = -2LL * L * a + b;
        d1[L] += val; d1[R+1] -= val;
        // constant term
        val = 1LL * a * L * L - 1LL * b * L + c;
        d0[L] += val; d0[R+1] -= val;
    }
    for(int i=1; i<=T; i++){
        d2[i] += d2[i-1]; d1[i] += d1[i-1]; d0[i] += d0[i-1];
        // add all the terms together to get the value of the function
        cout << d2[i] * i * i + d1[i] * i + d0[i] << " ";
    }
}
