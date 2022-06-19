#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize "Ofast"
#define ll long long
#define ull unsigned long long
#define MOD 1e9+7
#define fi first
#define se second
#define INF 0x3f3f3f3f
#define MAX 1005
#define pb push_back
#define LSB(S) (S & (-S))
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<piii> viii;

int n, leafs[MAX];
bool power[MAX][MAX], ok;
vii graph[MAX];

void dfs(int node, int pre, double flow){
    if(leafs[node]!=-1){
        if(flow < leafs[node]) ok = 0;
        return;
    }
    for(auto to: graph[node]){
        if(!ok) return;
        if(to.fi==pre) continue;
        double nflow = flow*((double)to.se/100);
        if(power[node][to.fi]) nflow *= nflow;
        dfs(to.fi, node, nflow);
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);  cout.tie(NULL);
    // freopen("input.txt", "r", stdin);
    cin >> n;
    for(int i=0, a, b, x, t; i<n-1; i++){
        cin >> a >> b >> x >> t;
        graph[a].pb({b, x});
        graph[b].pb({a, x});
        power[a][b] = power[b][a] = t;
    }
    for(int i=1; i<=n; i++) cin >> leafs[i];
    double lo = 0.0, high = 2*1000000000, eps = 0.0001, ans;
    while(high-lo>eps){
        double mid = lo + (high-lo)/2;
        ok = 1;
        dfs(1, -1, mid);
        if(ok){
            ans = mid;
            high = mid;
        }
        else{
            lo = mid;
        }
    }
    cout << fixed << setprecision(3) << ans << "\n";
    
    return 0;
}
