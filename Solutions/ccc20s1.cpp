#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize "Ofast"
#define ll long long
#define ull unsigned long long
#define MOD 1e9+7
#define fi first
#define se second
#define INF 0x3f3f3f3f
#define MAX 105
#define pb push_back
#define LSB(S) (S & (-S))
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<piii> viii;

bool comp(pii a, pii b){
    return a.fi < b.fi;
}

vii times;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);  cout.tie(NULL);
    int n;
    cin >> n;
    for(int i=0, a, b; i<n; i++){
        cin >> a >> b;
        times.pb({a, b});
    }
    sort(times.begin(), times.end(), comp);
    double ans = INT_MIN;
    for(int i=1; i<times.size(); i++){
        double speed = (double)(abs(times[i].se-times[i-1].se)) / (times[i].fi-times[i-1].fi);
        ans = max(ans, speed);
    }
    cout << fixed << setprecision(5) << ans << "\n";

    return 0;
}
