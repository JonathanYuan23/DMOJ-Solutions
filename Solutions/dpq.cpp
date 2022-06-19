#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize "Ofast"
#define frein freopen("input.txt", "r", stdin)
#define freout freopen("output.txt", "w", stdout)
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define nl '\n'
#define fi first
#define se second
#define INF 0x3f3f3f3f
#define MAX 200005
#define IMX INT_MAX
#define IMN INT_MIN
#define LLMX LONG_LONG_MAX
#define LLMN LONG_LONG_MIN
#define pb push_back
#define pf push_front
#define LSB(x) (x & (-x))
#define sz(x) (ll)(x.size())
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<pii, pii> piiii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<piii> viii;
typedef vector<piiii> viiii;

ll n, heights[MAX], vals[MAX], dp[MAX], st[4 * MAX];

void update(int i, int l, int r, int pos, ll val){
    if(l==r){
        st[i] = val;
        return;
    }
    int mid = (l + r) / 2;
    if(pos<=mid) update(i*2, l, mid, pos, val);
    else update(i*2+1, mid+1, r, pos, val);
    st[i] = max(st[i * 2], st[i * 2 + 1]);
}

ll rmq(int i, int ql, int qr, int l, int r){
    if(l>=ql && r<=qr) return st[i];
    int mid = (l + r) / 2;
    if(qr<=mid) return rmq(i*2, ql, qr, l, mid);
    if(ql>mid) return rmq(i*2+1, ql, qr, mid+1, r);
    return max(rmq(i*2, ql, qr, l, mid), rmq(i*2+1, ql, qr, mid+1, r));
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL);  cout.tie(NULL);
    cin >> n;
    for(int i=1; i<=n; i++) cin >> heights[i];
    for(int i=1; i<=n; i++) cin >> vals[i];
    for(int i=1; i<=n; i++){
        ll ans = vals[i];
        if(heights[i] > 1) ans = max(ans, rmq(1, 1, heights[i] - 1, 1, n) + vals[i]);
        dp[heights[i]] = ans;
        update(1, 1, n, heights[i], dp[heights[i]]);
    }
    cout << rmq(1, 1, n, 1, n) << nl;

    return 0;
};
