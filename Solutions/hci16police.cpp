#include <bits/stdc++.h>
using namespace std; 

#pragma GCC optimize "Ofast"
#define ll long long
#define MOD 1000000007
#define fi first
#define se second
#define INF 0x3f3f3f3f
#define MAXN 100005
#define pb push_back
#define LSB(S) (S & (-S))
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<piii> viii;
 
struct CHT {
 
    struct Line {
        int slope, yIntercept;
 
        Line(int slope, int yIntercept) : slope(slope), yIntercept(yIntercept) {}
 
        int val(int x) {
            return slope * x + yIntercept;
        }
 
        int intersect(Line y) {
            return (y.yIntercept - yIntercept + slope - y.slope - 1) / (slope - y.slope);
        }
    };
 
    deque<pair<Line, int>> dq;
    // each element holds the line (slope/y-intercept), and the intersection with the LAST line
 
    void insert(int slope, int yIntercept) {
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
 
    int query(int x) {
 
        // find first intersection that is greater than the x-val, the line before this will have the lowest y-val
        while (dq.size() > 1) {
            if (dq[1].second <= x) dq.pop_front();
            else break;
        }
 
        return dq[0].first.val(x);
    }
};

int N, H, pris[MAXN], dp[MAXN];
CHT hull;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);  cout.tie(NULL);
    //("input.txt", "r", stdin);
    //("output.txt", "w", stdout);
    cin >> N >> H;
    for(int i=0; i<N; i++) cin >> pris[i];
    dp[0] = H;
    hull.insert(-2*pris[0], pris[0]*pris[0]);
    for(int i=1; i<N; i++){
        dp[i] = dp[i-1]+H;
        dp[i] = min(dp[i], hull.query(pris[i])+(pris[i]*pris[i]+H));
        hull.insert(-2*pris[i], pris[i]*pris[i]+dp[i-1]);
    }
    cout << dp[N-1] << "\n";

    return 0;
}
