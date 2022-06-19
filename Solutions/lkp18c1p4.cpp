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
#define INF 0x3f3f3f3f
#define MAX 100005
#define IMX INT_MAX
#define LLMX LONG_LONG_MAX
#define pb push_back
#define pf push_front
#define LSB(x) (x & (-x))
#define sz(x) (int)(x.size())
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef pair<ll, pll> plll;
typedef pair<pii, pii> piiii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<piii> viii;
typedef vector<piiii> viiii;

int N, M, A, B, C, flag[MAX];
ll dis[MAX];
viii adj[MAX];

void spfa(){
    for(int i=1; i<=N; i++) dis[i] = LLMX;
    priority_queue<plll, vector<plll>, greater<plll>> pq;
    pq.push({0, {0, A}});
    dis[A] = 0;
    while(!pq.empty()){
        ll time = pq.top().se.fi, u = pq.top().se.se;
        pq.pop();
        if(flag[u]) continue;
        flag[u] = 1;
        for(auto to: adj[u]){
            ll level = to.fi, v = to.se.fi, cost = to.se.se;
            if(time + cost > C) continue;
            if(dis[v] > max(dis[u], level)){
                dis[v] = max(dis[u], level);
                if(!flag[v]) pq.push({dis[v], {time + cost, v}});
            }
        }
    }
    if(dis[B] == LLMX) cout << -1 << '\n';
    else cout << dis[B]<< '\n';
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL);  cout.tie(NULL);
    cin >> N >> M;
    for(int i=0, u, v, c; i<M; i++){
        cin >> u >> v >> c;
        adj[u].pb({i+1, {v, c}});
        adj[v].pb({i+1, {u, c}});
    }
    cin >> A >> B >> C;
    spfa();
    
    return 0;
}
