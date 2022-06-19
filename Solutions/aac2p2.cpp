#pragma GCC optimize "Ofast"
#include <bits/stdc++.h>
using namespace std; using pii = pair<int, int>;  using piii = pair<int, pii>;  using piiii = pair<pii, pii>;  using vi = vector<int>;  using vii = vector<pii>;  using viii = vector<piii>;  using viiii = vector<piiii>; using ll = long long; using ull = unsigned long long; 
#define frein freopen("input.txt", "r", stdin)
#define freout freopen("output.txt", "w", stdout)
#define fi first
#define se second
#define pb push_back
#define pf push_front
#define ppb pop_back
#define LSB(x) (x & (-x))
#define sz(x) (int)(x.size())

const int MOD = 1000000007, INF = 0x3f3f3f3f, MX = 5000, IMX = INT_MAX, IMN = INT_MIN;
const long long LLMX = LONG_LONG_MAX, LLMN = LONG_LONG_MIN;
const char nl = '\n';

ll n, oreos[MX];
unordered_map<ll, bool> occ;

int solve(){
    if(n == 1) return 1;
    if(n == 2) return ((oreos[0] + oreos[1]) % 2 == 0) ? 2 : 1;
    for(int i=0; i<n-2; i++){
        for(int j=i+2; j<n; j++){
            int sum = oreos[i] + oreos[j];
            if(!(sum % 2) && occ[sum / 2]) return 3;
        }   
    }
    return 2;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL);  cout.tie(NULL); 
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> oreos[i];
        occ[oreos[i]] = 1;
    }
    sort(oreos, oreos+n);
    cout << solve() << nl;
    return 0;
}
