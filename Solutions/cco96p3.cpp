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
#define MAX 1050
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

int n, dp1[7][MAX], dp2[7][MAX];
bool black[7][MAX];
string q1, q2;  

void solve(int dp[7][MAX], string &q, int pixels, int level, int node, int &i){
    if(q[i] != 'p'){
        dp[level][node] = ((q[i] == 'e') ? 0 : pixels);
        if(q[i] == 'f') black[level][node] = 1;
        i++;
    }
    else{
        for(int j=1; j<=4; j++){
            if(j==1){
                i++;
                solve(dp, q, pixels / 4, level + 1, (node - 1) * 4 + j, i);
            }
            else solve(dp, q, pixels / 4, level + 1, (node - 1) * 4 + j, i);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);  cout.tie(NULL);
    cin >> n;
    for(int tc=0; tc<n; tc++){
        cin >> q1 >> q2;
        int idx = 0;
        solve(dp1, q1, 1024, 1, 1, idx);
        idx = 0;
        solve(dp2, q2, 1024, 1, 1, idx);
        for(int i=6; i>=2; i--){
            for(int j=1; j<=pow(4, i-1); j++){
                int par = (int) ceil( (double) (j) / 4);
                if(!dp1[i][j] && dp2[i][j]) dp1[i][j] = dp2[i][j];
                if(!black[i-1][par]) dp1[i-1][par] += dp1[i][j];
            }
        }
        if(q1[0] == 'f' || q2[0] == 'f') cout << "There are 1024 black pixels." << nl;
        else cout << "There are " << dp1[1][1] << " black pixels." << nl;
        memset(dp1, 0, sizeof dp1);
        memset(dp2, 0, sizeof dp2);
        memset(black, 0, sizeof black);
    }
    
    return 0;
};
