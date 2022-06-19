#include <bits/stdc++.h>
using namespace std; 

#pragma GCC optimize "Ofast"
#define ll long long
#define MOD 1e9+7
#define fi first
#define se second
#define INF 0x3f3f3f3f
#define MAX 1000005
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
        ll val(int x) {return slope * x + yIntercept;}
        int intersect(Line y) {return (int)ceil((double)(y.yIntercept - yIntercept) / (slope - y.slope));}
    };
    deque<pair<Line, ll>> dq;
    void insert(ll slope, ll yIntercept) {
        Line newLine(slope, yIntercept);
        while (dq.size() > 1 && dq.back().second >= dq.back().first.intersect(newLine)) dq.pop_back();
        if (dq.empty()) {dq.emplace_back(newLine, 0); return;}
        dq.emplace_back(newLine, dq.back().first.intersect(newLine));
    }
    ll query(ll x) {
        while (dq.size() > 1) {
            if (dq[1].second <= x) dq.pop_front();
            else break;
        }
        return dq[0].first.val(x);
    }
};

ll n, a, b, c;
ll dp[MAX], sum[MAX];
CHT hull;

ll adjust(ll x){
    return a * (x * x) + b * x + c;
}
/*

    dp[i] = max(dp[i], adjust(i, j) + dp[j-1])

*/

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);  cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> a >> b >> c;
    for(int i=1; i<=n; i++){
        cin >> sum[i];
        if(i>1) sum[i] += sum[i-1];
    }
    dp[1] = adjust(sum[1]);
    hull.insert(-2*a*sum[1], dp[1]+(a*(sum[1]*sum[1]))-(b*sum[1]));
    for(int i=2; i<=n; i++){
        dp[i] = adjust(sum[i]);
        dp[i] = max(dp[i], hull.query(sum[i]) + (a*(sum[i]*sum[i]))+(b*sum[i])+c);
        hull.insert(-2*a*sum[i], dp[i]+(a*(sum[i]*sum[i]))-(b*sum[i]));
    }
    cout << dp[n] << "\n";

    return 0;
}
