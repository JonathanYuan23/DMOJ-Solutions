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

const int MOD = 1000000007, INF = 0x3f3f3f3f, MX = 10005, IMX = INT_MAX, IMN = INT_MIN;
const long long LLMX = LONG_LONG_MAX, LLMN = LONG_LONG_MIN;
const char nl = '\n';

int N, M;
bool grid[MX][MX];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);  cout.tie(0);
    cin >> N >> M;
    for(int i=0, r, c, w, h; i<M; i++){
        cin >> c >> r >> w >> h;
        r++, c++;
        grid[r][c] ^= 1, grid[r][c+w] ^= 1, grid[r+h][c] ^= 1, grid[r+h][c+w] ^= 1;
    }
    int ans = 0;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            grid[i][j] ^= grid[i-1][j] ^ grid[i][j-1] ^ grid[i-1][j-1], ans += grid[i][j];
        }
    }
    cout << ans << nl;
    return 0;
}
