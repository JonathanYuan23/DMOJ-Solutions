#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize "Ofast"
#define fre freopen("input.txt", "r", stdin)
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define fi first
#define se second
#define INF 0x3f3f3f3f3f3f3f3f
#define MAX 100005
#define pb push_back
#define LSB(S) (S & (-S))
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<piii> viii;

// dp[i][1] current node is painted black, dp[i][0] current node is painted white
ll n, dp[MAX][2];
vi graph[MAX];

void dfs(int node, int pre){
    dp[node][0] = dp[node][1] = 1;
    for(auto to: graph[node]){
        if(to==pre) continue;
        dfs(to, node);
        dp[node][1] = (dp[node][1] * dp[to][0]) % MOD;
        dp[node][0] = (dp[node][0] * ((dp[to][0] + dp[to][1]) % MOD)) % MOD;
    }
}

int main()
{
    /*
    CURRENT WHITE: IT'S CHILDREN CAN BE EITHER COLOUR

          w
        /   \
       w     w 

          w
        /   \
       w     b

          w
        /   \
       b     w

          w
        /   \
       b     b

    */

    /*
    CURRENT BLACK: IT'S CHILDREN CAN ONLY BE WHITE

          b
        /   \
       w     w 

    */
    ios_base::sync_with_stdio(0); cin.tie(NULL);  cout.tie(NULL);
    cin >> n;
    for(int i=0, u, v; i<n-1; i++){
        cin >> u >> v;
        graph[u].pb(v);
        graph[v].pb(u);
    }
    dfs(1, -1);
    cout << (dp[1][0] + dp[1][1]) % MOD << '\n';

    return 0;
}
