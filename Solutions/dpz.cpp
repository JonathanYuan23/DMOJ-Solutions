#include <bits/stdc++.h>
using namespace std; 

#pragma GCC optimize "Ofast"
#define ll long long
#define MOD 1000000007
#define fi first
#define se second
#define INF 0x3f3f3f3f
#define MAXN 200005
#define pb push_back
#define LSB(S) (S & (-S))
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<piii> viii;
 
struct CHT {
 
    struct Line {
        ll slope, yIntercept;
 
        Line(ll slope, ll yIntercept) : slope(slope), yIntercept(yIntercept) {}
 
        ll val(ll x) {
            return slope * x + yIntercept;
        }
 
        ll intersect(Line y) {
            return (y.yIntercept - yIntercept + slope - y.slope - 1) / (slope - y.slope);
        }
    };
 
    deque<pair<Line, ll>> dq;
    // each element holds the line (slope/y-intercept), and the intersection with the LAST line
 
    void insert(ll slope, ll yIntercept) {
        Line newLine(slope, yIntercept);
 
        // dq.back().second is the intersection of the last line with the second last line
        // dq.back().first is the last line
        while (dq.size() > 1 && dq.back().second >= dq.back().first.intersect(newLine))
            dq.pop_back();
 
        if (dq.empty()) {
            dq.emplace_back(newLine, 0);
            return;
        }
 
        dq.emplace_back(newLine, dq.back().first.intersect(newLine));
    }
 
    ll query(ll x) {
 
        // find first intersection that is greater than the x-val, the line before this will have the lowest y-val
        while (dq.size() > 1) {
            if (dq[1].second <= x) dq.pop_front();
            else break;
        }
 
        return dq[0].first.val(x);
    }
};

ll N, C, f[MAXN], dp[MAXN];
CHT hull;

/*

    dpi = min(dpi, dpj+(fi-fj)^2+C) for all j<i
        = dpj + fi^2 - 2fifj + fj^2 + C
        = -2fjfi + dpj + fj^2 + fi^2 + C
      y =  m  x  +     b

*/

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);  cout.tie(NULL);
    cin >> N >> C;
    for(ll i=0; i<N; i++) cin >> f[i];
    dp[0] = 0;
    hull.insert(-2*f[0], dp[0]+f[0]*f[0]);
    for(ll i=1; i<N; i++){
        dp[i] = hull.query(f[i])+f[i]*f[i]+C;
        hull.insert(-2*f[i], dp[i]+f[i]*f[i]);
    }
    cout << dp[N-1] << "\n";

    return 0;
}
