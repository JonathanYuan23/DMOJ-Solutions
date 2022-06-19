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

const int MOD = 1000000007, INF = 0x3f3f3f3f, MX = 500005, IMX = INT_MAX, IMN = INT_MIN;
const long long LLMX = LONG_LONG_MAX, LLMN = LONG_LONG_MIN;
const char nl = '\n';

int N, a[MX], b[MX], s[655][655], slim = 651;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);  cout.tie(0);
    cin >> N;  
    for(int i=1; i<=N; i++) {
        cin >> a[i] >> b[i];   
        a[i]++, b[i]++, s[a[i]][b[i]]++;
    }
    for(int i=1; i<=slim; i++) for(int j=1; j<=slim; j++) s[i][j] += s[i-1][j] + s[i][j-1] - s[i-1][j-1];
    for(int i=1; i<=N; i++) {
        int above = s[slim][slim] - s[slim][b[i]] - s[a[i]][slim] + s[a[i]][b[i]], below = s[a[i]-1][b[i]-1];
        if(a[i] == slim) below += s[1][b[i]] - s[1][b[i]-1];
        if(b[i] == slim) below += s[a[i]][1] - s[a[i]-1][1];
        cout << above + 1 << " " << (N - below) << nl;
    }
}
