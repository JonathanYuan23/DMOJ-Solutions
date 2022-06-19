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
#define MAX 10005
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

int n, shoes[MAX];
double dp[MAX];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);  cout.tie(NULL);
    cin >> n;
    for(int i=1; i<=n; i++) cin >> shoes[i];
    for(int i=1; i<=n; i++){
        dp[i] = shoes[i] + dp[i-1];
        if(i - 2 >= 0){
            double s1 = shoes[i], s2 = shoes[i-1];
            if(s2 < s1) swap(s1, s2);
            dp[i] = min(dp[i], dp[i - 2] + (s1 / 2) + s2);
        }
        if(i - 3 >= 0){
            double s1 = shoes[i], s2 = shoes[i-1], s3 = shoes[i-2];
            dp[i] = min(dp[i], dp[i - 3] + (s1 + s2 + s3) - min(s1, min(s2, s3)));
        }
    }
    cout << fixed << setprecision(1) << dp[n] << nl;
    
    return 0;
};
