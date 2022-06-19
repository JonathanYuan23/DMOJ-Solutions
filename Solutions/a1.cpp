#pragma GCC optimize "Ofast"
#include <bits/stdc++.h>
using namespace std; using pii = pair<int, int>;  using piii = pair<int, pii>;  using piiii = pair<pii, pii>;  using vi = vector<int>;  using vii = vector<pii>;  using viii = vector<piii>;  using viiii = vector<piiii>;
#define frein freopen("input.txt", "r", stdin)
#define freout freopen("output.txt", "w", stdout)
#define ll long long
#define ull unsigned long long
#define fi first
#define pb push_back
#define pf push_front
#define LSB(x) (x & (-x))
#define sz(x) (int)(x.size())

const int MOD = 1000000007, INF = 0x3f3f3f3f, MX = 1005, IMX = INT_MAX, IMN = INT_MIN;
const long long LLMX = LONG_LONG_MAX, LLMN = LONG_LONG_MIN;
const char nl = '\n';

int n, m;
string s;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL);  cout.tie(NULL);
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> m; cin.ignore();
        --m;
        getline(cin, s);
        cout << i << ' ';
        for(int j=0; j<sz(s); j++) if(j != m) cout << s[j];
        cout << nl;
    }
    
    return 0;
}
