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

const int MOD = 1e9+7, INF = 0x3f3f3f3f, MX = 1.5e5 + 5, IMX = INT_MAX, IMN = INT_MIN;
const long long LLMX = LONG_LONG_MAX, LLMN = LONG_LONG_MIN;
const char nl = '\n';

int N, M, dif[17][MX], arr[MX], st[4*MX], x[MX], y[MX], z[MX];

void build(int i, int l, int r){
    if(l==r){
        st[i] = arr[l];
        return;
    }
    int mid = (l + r) / 2;
    build(i*2, l, mid);
    build(i*2+1, mid+1, r);
    st[i] = __gcd(st[i*2], st[i*2+1]);
}

int query(int i, int ql, int qr, int l, int r){
    if(l>=ql && r<=qr) return st[i];
    int mid = (l + r) / 2;
    if(qr<=mid) return query(i*2, ql, qr, l, mid);
    if(ql>mid) return query(i*2+1, ql, qr, mid+1, r);
    return __gcd(query(i*2, ql, qr, l, mid), query(i*2+1, ql, qr, mid+1, r));
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);  cout.tie(0);
    cin >> N >> M;
    for(int i=1; i<=M; i++) {
        cin >> x[i] >> y[i] >> z[i];
        dif[z[i]][x[i]]++, dif[z[i]][y[i] + 1]--;
    }
    for(int i=1; i<=N; i++) {
        int x = 1;
        for(int j=1; j<=16; j++) {
            dif[j][i] += dif[j][i-1];
            if(dif[j][i] > 0) x = x * j / __gcd(x, j);
        }
        arr[i] = x;
    }
    build(1, 1, N);
    for(int i=1; i<=M; i++) {
        if(query(1, x[i], y[i], 1, N) != z[i]) {
            cout << "Impossible\n";
            return 0;
        }
    }
    for(int i=1; i<=N; i++) cout << arr[i] << ' ';
    return 0;
}
