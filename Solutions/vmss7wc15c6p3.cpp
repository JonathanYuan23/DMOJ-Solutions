#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize "Ofast"
#define ll long long
#define ull unsigned long long
#define MOD 1e9+7
#define fi first
#define se second
#define INF 0x3f3f3f3f
#define MAX 400005
#define pb push_back
#define LSB(S) (S & (-S))
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<piii> viii;

int agri[MAX];
vi graph[MAX];

int dfs(int node){
    for(auto to: graph[node]) agri[node] += dfs(to);
    return agri[node];
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);  cout.tie(NULL);
    int n; 
    cin >> n;
    for(int i=0, a, b; i<n-1; i++){
        cin >> a >> b;
        --a; 
        --b;
        graph[a].pb(b);
    }
    for(int i=0, a; i<n; i++) cin >> agri[i];
    dfs(0);
    int ans = INT_MIN;
    for(int i=0; i<n; i++) ans = max(ans, agri[i]);
    cout << ans << '\n';
    
    return 0;
}
