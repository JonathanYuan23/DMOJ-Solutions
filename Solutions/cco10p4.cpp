#pragma GCC optimize "Ofast"
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MOD 1000000009
#define fi first
#define se second
#define INF 0x3f3f3f3f
#define MAXN 3005
#define pb push_back
#define LSB(S) (S & (-S))
typedef pair<int, int> pii;
typedef pair<pair<int, int>, int> piii;

int dp[6][MAXN];
vector<pii> types[6];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL);  cout.tie(NULL);
    int T, N, B, c, v, t;
    cin >> T >> N;
    for(int i=0; i<N; i++){
        cin >> c >> v >> t;
        types[t].pb({c, v});
    }
    cin >> B;
    for(int i=1; i<=T; i++){
        for(int j=0; j<=B; j++){
            dp[i][j] = max(dp[i][j], dp[i - 1][j]);
            for(auto x: types[i]){
                if(x.fi<=j){
                    dp[i][j] = max(dp[i][j], x.se+dp[i-1][j-x.fi]);
                }
            }
        }
    }
    cout << ((dp[T][B]>0)?dp[T][B]:-1) << "\n";
    
    return 0;
}
