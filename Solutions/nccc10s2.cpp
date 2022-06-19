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

const int MOD = 1e9+7, INF = 0x3f3f3f3f, MX = 1e4+5, IMX = INT_MAX, IMN = INT_MIN;
const long long LLMX = LONG_LONG_MAX, LLMN = LONG_LONG_MIN;
const char nl = '\n';

int N, K, freq[MX][26], in[26], dist[26];
vi adj[26];
queue<int> q;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);  cout.tie(0);
    cin >> N >> K;
    string s, s1;
    for(int i=0; i<N; i++) {
        cin >> s;
        if(!i) 
            s1 = s;
        for(int j=0; j<K; j++) 
            freq[i][s[j] - 'A'] = j;
    }
    for(int i=0; i<K-1; i++) {
        for(int j=i+1, p, q; j<K; j++) {
            p = s1[i] - 'A', q = s1[j] - 'A';
            bool good = 1;
            for(int k=0; k<N; k++) {
                if(freq[k][p] > freq[k][q]) {
                    good = 0;
                    break;
                }
            }
            if(good) {
                adj[p].pb(q);
                in[q]++;
            }
        }
    }
    ms(dist, -1);
    for(int i=0; i<K; i++) {
        if(!in[i]) {
            dist[i] = 1;
            q.push(i);
        }   
    }
    int ans = 0;
    while(!q.empty()) {
        int u = q.front(); q.pop();
        ans = max(ans, dist[u]);
        for(auto &v: adj[u]) {
            if(--in[v] == 0) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    cout << ans << nl;
    return 0;
}
