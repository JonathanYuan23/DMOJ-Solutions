#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize "Ofast"
#define ll long long
#define MOD 1000000009
#define p 31
#define INF 0x3f3f3f3f
#define MAXN 15
#define pb push_back
#define LSB(S) (S & (-S))
typedef pair<int, int> pii;
typedef pair<pair<int, int>, int> piii;
typedef vector<int> vi;
typedef vector<vector<int>> vii;

int indeg[8] = {0, 1, 0, 0, 2, 1, 0, 1};
vector<int> graph[MAXN];

void solve(){
    graph[1].pb(7);
    graph[1].pb(4);
    graph[2].pb(1);
    graph[3].pb(4);
    graph[3].pb(5);
    int u, v;
    cin >> u >> v;
    while(u&&v){
        graph[u].pb(v);
        indeg[v]++;
        cin >> u >> v;
    }
    vector<int> res;
    priority_queue<int, vector<int>, greater<int>> q;
    for(int i=1; i<=7; i++) if(!indeg[i]) q.push(i);
    while(!q.empty()){
        u=q.top(); q.pop();
        res.pb(u);
        for(auto x: graph[u]) if(!(--indeg[x])) q.push(x);
    }
    if(res.size()>=7) for(int i=0; i<7; i++) cout << res[i] << " ";
    else cout << "Cannot complete these tasks. Going to bed.\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL);  cout.tie(NULL);
    solve();

    return 0;
}
