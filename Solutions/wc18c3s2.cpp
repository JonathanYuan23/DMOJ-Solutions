#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize "Ofast"
#define ll long long
#define ull unsigned long long
#define MOD 1e9+7
#define fi first
#define se second
#define INF 0x3f3f3f3f
#define MAX 200005
#define pb push_back
#define LSB(S) (S & (-S))
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<piii> viii;

int n, k, f;
bool path[MAX];
vi graph[MAX];

bool prune(int node, int par){
    bool &ans = path[node];
    for(auto to: graph[node]){
        if(to == par) continue;
        ans |= prune(to, node);
    }
    return ans;
}

void dfs(int node, int par, int &sum, int &longest, int depth){
    longest = max(longest, depth);
    for(auto to: graph[node]){
        if(to == par || !path[to]) continue;
        sum++;
        dfs(to, node, sum, longest, depth+1);
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);  cout.tie(NULL);
    cin >> n >> k >> f;
    for(int i=0, a; i<k; i++){
        cin >> a;
        path[a] = 1;
    }
    for(int i=0, a, b; i<n-1; i++){
        cin >> a >> b;
        graph[a].pb(b);
        graph[b].pb(a);
    }
    prune(1, -1);
    int sum1 = 0, sum2 = 0, longest = INT_MIN, ans = INT_MAX;
    dfs(1, -1, sum1, longest, 0);
    ans = min(ans, 2*sum1-longest);
    path[f] = 1; 
    prune(1, -1);
    dfs(1, -1, sum2, longest, 0);
    cout << min(ans, sum2) << '\n';
        
    return 0;
}
