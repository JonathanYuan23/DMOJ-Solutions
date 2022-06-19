#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize "Ofast"
#define ll long long
#define ull unsigned long long
#define MOD 1e9+7
#define fi first
#define se second
#define INF 0x3f3f3f3f
#define MAX 100005
#define pb push_back
#define LSB(S) (S & (-S))
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<piii> viii;

int N, V, coins[MAX], dp[MAX], ans[MAX];
piii stores[MAX];

bool comp(piii a, piii b) {
    return a.fi < b.fi;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL);  cout.tie(NULL);
    cin >> N >> V;
    for(int i=1; i<=N; i++) cin >> coins[i];
    for(int i=0, c, l; i<V; i++){
        cin >> c >> l;
        stores[i] = {l, {i, c}};
    }
    sort(stores, stores + V);
    memset(dp, INF, sizeof dp);
    dp[0] = 0;
    int k = 0;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=MAX/10; j++)
            if(coins[i]<=j) 
                dp[j] = min(dp[j], dp[j-coins[i]]+1);
        while(stores[k].fi == i && k < V){
            piii a = stores[k];
            k++;
            ans[a.se.fi] = dp[a.se.se];
        }
    }
    for(int i=0; i<V; i++) 
        cout << ((ans[i]==INF) ? -1 : ans[i]) << '\n';

    return 0;
}
