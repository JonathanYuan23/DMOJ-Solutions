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
#define MAX 100005
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

int n, arr[MAX], pmax[MAX], psa[MAX], dp[MAX];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);  cout.tie(NULL);
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> arr[i];
        pmax[i] = max(arr[i], pmax[i-1]);
    }
    dp[0] = psa[0] = 1;
    for(int i=1; i<=n; i++){
        if(arr[i] >= pmax[i-1]){
            dp[i] = psa[i-1];
            psa[i] = (dp[i] + psa[i-1]) % MOD;
        }   
        else{
            dp[i] = dp[i-1];
            psa[i] = (dp[i] + psa[i-1]) % MOD;
        }
    }
    cout << dp[n] << nl;
    
    return 0;
};
