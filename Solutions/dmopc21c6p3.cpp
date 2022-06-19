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

const int MOD = 1e9+7, INF = 0x3f3f3f3f, MX = 1505, IMX = INT_MAX, IMN = INT_MIN;
const long long LLMX = LONG_LONG_MAX, LLMN = LONG_LONG_MIN;
const char nl = '\n';

int N, M, K, draw[MX][MX], dist[MX][MX], dx[4] = {0, 1, 0, -1}, dy[4] = {-1, 0, 1, 0};
queue<pii> q;

bool valid(int nu, int nv) {
    return nu >= 0 && nu < N && nv >= 0 && nv < M;
}

bool useColor(int i, int j) {
    return 
    (i-1 >= 0 && !draw[i-1][j]) || (i+1 < N && !draw[i+1][j]) || (j-1 >= 0 && !draw[i][j-1]) || (j+1 < M && !draw[i][j+1]);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);  cout.tie(0);
    cin >> N >> M >> K;
    ms(dist, -1);
    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++) 
            cin >> draw[i][j];
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            if(draw[i][j]) {
                dist[i][j] = 0;
                if(useColor(i, j)) 
                    q.push({i, j});
            }
        }
    }
    while(!q.empty()) {
        pii pix = q.front(); q.pop();
        int u = pix.fi, v = pix.se;

        for(int i=0, nu, nv; i<4; i++) {

            nu = u + dy[i], nv = v + dx[i];

            if(!valid(nu, nv)) continue;

            // closest color
            if(dist[nu][nv] == -1 && dist[u][v] + 1 <= K) {
                draw[nu][nv] = draw[u][v];
                dist[nu][nv] = dist[u][v] + 1;
                q.push({nu, nv});
            }

            // tie for closest
            else if(dist[nu][nv] == dist[u][v] + 1 && dist[nu][nv] && draw[nu][nv] > draw[u][v]) {
                draw[nu][nv] = draw[u][v];
                dist[nu][nv] = dist[u][v] + 1;
                q.push({nu, nv});
            }
        }
    }

    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            cout << draw[i][j] << ' ';
        }
        cout << nl;
    }
}
