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
#define INF 0x3f3f3f3f3f3f3f3f
#define MAX 3005
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

ll n, a, q, query;
bool vis[MAX];
pii points[MAX];
vector<ll> res;

ll dist(int x1, int y1, int x2, int y2){
    return ((ll) x1 - x2) * (x1 - x2) + ((ll) y1 - y2) * (y1 - y2);
}

void dijkstra(){
    res.assign(n+1, LLMX);
    res[a] = 0;
    for(int i=0; i<n-1; i++){
        ll mn = LLMX, u;
        for(int j=1; j<=n; j++){
            if(res[j] < mn && !vis[j]){
                mn = res[j];
                u = j;
            }
        }
        vis[u] = 1;
        if(res[u] == LLMX) continue;
        for(int to=1; to<=n; to++){
            ll cost = dist(points[to].fi, points[to].se, points[u].fi, points[u].se);
            if(!vis[to] && res[to] > res[u] + cost) res[to] = res[u] + cost;
        }
    }
    res.erase(res.begin());
    sort(res.begin(), res.end());
}

int solve(){
    int lo = 0, high = sz(res) - 1, best = -1;
    while(lo <= high){
        int mid = (lo + high) / 2;
        if(res[mid] <= query){
            best = mid;
            lo = mid + 1;
        }
        else high = mid - 1;
    }
    return best + 1;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL);  cout.tie(NULL);
    cin >> n;
    for(int i=1; i<=n; i++) cin >> points[i].fi >> points[i].se;
    cin >> a >> q;
    dijkstra();
    while(q--){
        cin >> query;
        cout << solve() << nl;
    }
    return 0;
};
