#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize "Ofast"
#define ll long long
#define ull unsigned long long
#define MOD 1e9+7
#define fi first
#define se second
#define INF 0x3f3f3f3f
#define MAX 15
#define pb push_back
#define LSB(S) (S & (-S))
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<piii> viii;

vi graph[MAX];

int ways(int node){
    if(!graph[node].size()) return 1;
    int ans = 0;
    for(auto to: graph[node]){
        if(!ans) ans += ways(to)+1;
        else ans *= (ways(to)+1);
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);  cout.tie(NULL);
    int n; cin >> n;
    for(int i=1, v; i<=n-1; i++){
        cin >> v;
        graph[v].pb(i);
    }
    cout << ways(n) << "\n";
    return 0;
}
