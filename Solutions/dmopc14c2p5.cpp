#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize "Ofast"
#define frein freopen("input.txt", "r", stdin)
#define freout freopen("output.txt", "w", stdout)
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define fi first
#define se second
#define INF 0x3f3f3f3f3f3f3f3f
#define MAX 1000005
#define pb push_back
#define LSB(S) (S & (-S))
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<pii, pii> piiii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<piii> viii;
typedef vector<piiii> viiii;

int N, M;
double dp[MAX];
vi graph[MAX];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL);  cout.tie(NULL);
    cin >> N >> M;
    for(int i=0, u, v; i<M; i++){
        cin >> u >> v;
        graph[u].pb(v);
    }
    dp[1] = 1.0;
    for(int i=1; i<=N; i++){
        double children = dp[i] / graph[i].size();
        for(auto to: graph[i]) dp[to] += children;
    }
    cout << fixed << setprecision(9);
    for(int i=1; i<=N; i++) if(!graph[i].size()) cout << dp[i] << '\n';

    return 0;
}
