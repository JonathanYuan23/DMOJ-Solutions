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
#define MAX 505
#define IMX INT_MAX
#define IMN INT_MIN
#define LLMX LONG_LONG_MAX
#define LLMN LONG_LONG_MIN
#define pb push_back
#define pf push_front
#define LSB(x) (x & (-x))
#define sz(x) (ll)(x.size())
#define umap unordered_map
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<pii, pii> piiii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<piii> viii;
typedef vector<piiii> viiii;  

int T, N, dp[MAX * 10], traceback[MAX * 10], music[MAX], track[MAX];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL);  cout.tie(NULL);
    cin >> T >> N;
    dp[0] = 1;
    for(int i=0; i<N; i++){
        cin >> music[i];
        for(int j=T; j>=music[i]; j--){
            if(!dp[j] && dp[j-music[i]]){
                dp[j] = 1;
                traceback[j] = i;
            }
        }
    }
    int cur = T;
    while(!dp[cur]) cur--;
    for(int i=cur; i>0; i -= music[traceback[i]]) track[traceback[i]] = 1;
    int t0 = 0, t1 = 0;
    for(int i=0; i<N; i++){
        if(!track[i]){
            cout << t0 << ' ';
            t0 += music[i];
        }
        else{
            cout << t1 << ' ';
            t1 += music[i];
        }
    }
    cout << nl;
    return 0;
}
