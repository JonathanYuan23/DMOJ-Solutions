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

const int MOD = 1e9+7, INF = 0x3f3f3f3f, MX = 200005, IMX = INT_MAX, IMN = INT_MIN;
const long long LLMX = LONG_LONG_MAX, LLMN = LONG_LONG_MIN;
const char nl = '\n';

ll hsh[MX], hsh2[MX], power[MX], power2[MX];
int n, m, base = 137, base2 = 139, nf[26], mf[26];
string needle, haystack;
set<pair<ll, ll>> hashes;

bool equal() {
    for(int i=0; i<26; i++) if(nf[i] != mf[i]) return false;
    return true;
}

pair<ll, ll> substrHash(int L, int R) {
    long h1 = (hsh[R] - (hsh[L-1] * power[R-L+1] % MOD) % MOD + MOD) % MOD, h2 = (hsh2[R] - (hsh2[L-1] * power2[R-L+1] %MOD) % MOD + MOD) % MOD;
    return {h1, h2};
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);  cout.tie(0);
    cin >> needle >> haystack;
    n = sz(needle), m = sz(haystack);
    for(int i=0; i<n; i++) nf[needle[i] - 'a']++;
    power[0] = power2[0] = 1;
    for(int i=1; i<=m; i++) {
        hsh[i] = (((hsh[i-1] * base) % MOD) + haystack[i-1] - 'a') % MOD;
        hsh2[i] = (((hsh2[i-1] * base2) % MOD) + haystack[i-1] - 'a') % MOD;
        power[i] = (power[i-1] * base) % MOD;
        power2[i] = (power2[i-1] * base2) % MOD;
    }
    for(int i=1; i<=m; i++) {
        mf[haystack[i-1] - 'a']++;
        if(i > n) mf[haystack[i-1-n] - 'a']--;
        if(equal()) hashes.insert(substrHash(i-n+1, i));
    }
    cout << sz(hashes) << nl;
    return 0;
}
