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
#define pb push_back
#define LSB(x) (x & (-x))
#define sz(x) (int)(x.size())
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<int, pii> piii;
typedef pair<pii, pii> piiii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<piii> viii;
typedef vector<piiii> viiii;

ll dis[MAX], n, c, K, v[MAX];
bool vis[MAX];
vii adj[MAX];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL);  cout.tie(NULL);
    cin >> n >> c >> K;
    for(int i=1; i<=n; i++) cin >> v[i];
    for(int i=1, count; i<=n; i++){
        cin >> count;
        for(int j=0, clas; j<count; j++){
            cin >> clas;
            adj[i].pb({0, clas});
            adj[clas].pb({1, i});
        }
    }
    memset(vis, 0, sizeof vis);
    for(int i=1; i<=n; i++) dis[i] = LONG_LONG_MAX;
    priority_queue<pli, vector<pli>, greater<pli>> pq;
    pq.push({0, 1});
    dis[1] = 0;
    while(!pq.empty()){
        int student = pq.top().se;
        pq.pop();
        if(vis[student]) continue;
        vis[student] = 1;
        for(auto to: adj[student]){
            if(to.fi == 1) continue;
            for(auto nStudent: adj[to.se]){
                if(!nStudent.fi || nStudent.se == student) continue;
                ll cost = abs(v[student] - v[nStudent.se]) + K;
                if(dis[nStudent.se] > dis[student] + cost){
                    dis[nStudent.se] = dis[student] + cost;
                    if(!vis[nStudent.se]) pq.push({dis[nStudent.se], nStudent.se});
                }
            }
        }
    }
    for(int i=1; i<=n; i++) cout << ((dis[i] == LONG_LONG_MAX) ? -1 : dis[i]) << '\n';
    
    return 0;
}
