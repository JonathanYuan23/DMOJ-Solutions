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

int N, Q;
vector<ll> points;

int query(ll radius){
    int lo = 0, high = sz(points) - 1, ret = -1;
    while(lo <= high){
        int mid = (lo + high) / 2;
        if(points[mid] <= radius){
            ret = max(ret, mid);
            lo = mid + 1;
        }
        else high = mid - 1;
    }
    return ret + 1;
}   

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);  cout.tie(0);
    cin >> N >> Q;
    for(int i=0, x, y; i<N; i++){
        cin >> x >> y;
        points.pb(1LL * x * x + 1LL * y * y);
    }
    sort(points.begin(), points.end());
    for(int i=0, r; i<Q; i++){
        cin >> r;
        cout << query(1LL * r * r) << nl;
    }
}
