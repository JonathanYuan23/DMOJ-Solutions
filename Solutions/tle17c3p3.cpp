#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize "Ofast"
#define ll long long
#define ull unsigned long long
#define MOD 1e9+7
#define fi first
#define se second
#define INF 0x3f3f3f3f
#define MAX 300005
#define pb push_back
#define LSB(S) (S & (-S))
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<piii> viii;

vi graph[MAX];
int N, M, Q[MAX];

int dfs(int node){
    if(!graph[node].size()) return Q[node];
    int ans = INT_MAX;
    for(auto to: graph[node]) ans = min(ans, dfs(to));
    return Q[node] + ans;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);  cout.tie(NULL);
    cin >> N >> M;
    for(int i=0, t, r, v; i<M; i++){
        cin >> t >> r;
        for(int j=0; j<r; j++){
            cin >> v;
            graph[t].pb(v);
        }
    }
    for(int i=1; i<=N; i++) cin >> Q[i];
    cout << dfs(1) << "\n";
    return 0;
}
