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

const int MOD = 1e9+7, INF = 0x3f3f3f3f, MX = 1e6+5, IMX = INT_MAX, IMN = INT_MIN;
const long long LLMX = LONG_LONG_MAX, LLMN = LONG_LONG_MIN;
const char nl = '\n';

struct {
    int l, r, val;
} st[MX * 4];

int N, Q, ans = 0;

void push(int i){
    st[i].val = min(st[i*2].val, st[i*2+1].val);
}

void build(int i, int l, int r){
    st[i].l = l, st[i].r = r;
    if(l==r){
        cin >> st[i].val;
        return;
    }
    int mid = (l + r) / 2;
    build(i*2, l, mid);
    build(i*2+1, mid+1, r);
    push(i);
}

void update(int i, int pos, int val) {
    if(st[i].l == st[i].r) {
        st[i].val = val;
        return;
    }
    int m = (st[i].l + st[i].r) / 2;
    if(pos <= m) update(i * 2, pos, val);
    else update(i * 2 + 1, pos, val);
    push(i);
}

int query(int i, int ql, int qr, int k) {
    if(st[i].l == st[i].r) return st[i].val < k ? st[i].l : -1;
    if(st[i].val >= k) return -1;
    int m = (st[i].l + st[i].r) / 2;
    if(qr <= m) return query(i * 2, ql, qr, k);
    if(ql > m) return query(i * 2 + 1, ql, qr, k);
    int temp = query(i * 2, ql, m, k);
    return temp != -1 ? temp : query(i * 2 + 1, m + 1, qr, k);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);  cout.tie(0);
    cin >> N >> Q;
    build(1, 1, N);
    for(int i=0, op, x, y, k; i<Q; i++) {
        cin >> op >> x >> y;
        x ^= ans, y ^= ans;
        if(op == 1) update(1, x, y);
        else {
            cin >> k;
            k ^= ans;
            ans = query(1, x, y, k);
            cout << ans << nl;
        }
    }
    return 0;
}
