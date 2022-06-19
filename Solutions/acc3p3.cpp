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

const int MOD = 1e9+7, INF = 0x3f3f3f3f, MX = 1e5 + 5, IMX = INT_MAX, IMN = INT_MIN;
const long long LLMX = LONG_LONG_MAX, LLMN = LONG_LONG_MIN;
const char nl = '\n';

int n, si[MX];
string s[MX], res="", alpha="zyxwvutsrqponmlkjihgfedcba";

bool solve(char c) {
    int temp[n] = {0};
    for(int i=0; i<n; i++) {
        bool hasChar = 0;
        for(int j=si[i]; j<sz(s[i]); j++) {
            if(s[i][j] == c) {
                hasChar = 1;
                temp[i] = j + 1;
                break;
            }
        }
        if(!hasChar) return 0;
    }
    res += c;
    for(int i=0; i<n; i++) si[i] = temp[i];
    return 1;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);  cout.tie(0);
    cin >> n;
    for(int i=0; i<n; i++) cin >> s[i];
    for(int i=0; i<26; i++) 
        while(solve(alpha[i])){}
    cout << (!sz(res) ? "-1" : res) << nl;
    return 0;
}
