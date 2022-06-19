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
#define MAX 1005
#define IMX INT_MAX
#define IMN INT_MIN
#define LLMX LONG_LONG_MAX
#define LLMN LONG_LONG_MIN
#define pb push_back
#define pf push_front
#define LSB(x) (x & (-x))
#define sz(x) (ll)(x.size())
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<pii, pii> piiii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<piii> viii;
typedef vector<piiii> viiii;

int n, fee[MAX], dis[MAX][MAX], vis[MAX][MAX];

void dijkstra(){
    memset(dis, INF, sizeof dis);
    dis[2][1] = fee[2];
    priority_queue<piii, viii, greater<piii>> pq;
    // cost, node, last_jump_len
    pq.push({dis[2][1], {2, 1}});
    while(!pq.empty()){
        int cost = pq.top().fi, node = pq.top().se.fi, jumpLen = pq.top().se.se;
        pq.pop();
        if(vis[node][jumpLen]) continue;
        vis[node][jumpLen] = 1;
        int nextJump = jumpLen + 1;
        if(node + nextJump <= n){
            if(dis[node + nextJump][nextJump] > cost + fee[node + nextJump]){
                dis[node + nextJump][nextJump] = cost + fee[node + nextJump];
                if(!vis[node + nextJump][nextJump]) pq.push({dis[node + nextJump][nextJump], {node + nextJump, nextJump}});
            }
        }
        if(node - jumpLen >= 1){
            if(dis[node - jumpLen][jumpLen] > cost + fee[node - jumpLen]){
                dis[node - jumpLen][jumpLen] = cost + fee[node - jumpLen];
                if(!vis[node - jumpLen][jumpLen]) pq.push({dis[node - jumpLen][jumpLen], {node - jumpLen, jumpLen}});
            }
        }
    }
    int ans = IMX;
    for(int i=1; i<MAX; i++) ans = min(ans, dis[n][i]);
    cout << ans << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL);  cout.tie(NULL);
    cin >> n;
    for(int i=1; i<=n; i++) cin >> fee[i];
    dijkstra();

    return 0;
};
