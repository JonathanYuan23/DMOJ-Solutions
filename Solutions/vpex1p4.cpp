#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize "Ofast"
#define ll long long
#define ull unsigned long long
#define MOD 1e9+7
#define fi first
#define se second
#define INF 0x3f3f3f3f
#define MAX 100005
#define pb push_back
#define LSB(S) (S & (-S))
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<piii> viii;

int dp[35][2*MAX], idx[35][2*MAX], logt[2*MAX], dis[MAX], nodes, d, n, mnIndx;
vii graph[MAX], ban; vi height, last, euler;
ll res[2][MAX*10];

void construct(){
    int P=floor(log2(n));
    for(int i=0; i<n; i++){
        dp[0][i] = height[i];
        idx[0][i] = i;
    }
    for(int i=2; i<=n; i++) logt[i] = logt[i/2]+1;
    long long leftInterval, rightInterval;
    for(int i=1; i<=P; i++){
        for(int j=0; j+(1<<i)<=n; j++){
            leftInterval=dp[i-1][j]; rightInterval=dp[i-1][j+(1<<(i-1))];
            dp[i][j]=min(leftInterval, rightInterval);
            idx[i][j]=(leftInterval<=rightInterval) ? idx[i-1][j] : idx[i-1][j+(1<<(i-1))];
        }
    }
}

void rmq(int l, int r){
    int len = r-l+1, P=logt[len];
    long long leftInterval = dp[P][l], rightInterval = dp[P][r-(1<<P)+1];
    mnIndx=(leftInterval<=rightInterval) ? idx[P][l] : idx[P][r-(1<<P)+1];
}

void visit(int node, int depth){
    last[node]=euler.size();
    euler.push_back(node);
    height.push_back(depth);
}

int lca(int u, int v){
    int l = min(last[u], last[v]);
    int r = max(last[u], last[v]);
    rmq(l, r);
    return euler[mnIndx];
}

void process(int node, int par, int h){
    visit(node, h);
    for(auto to: graph[node]){
        if(to.fi != par){
            process(to.fi, node, h+1);
            visit(node, h);
        }
    }
}

void dfs(int node, int par, int h){
    dis[node] = h;
    for(auto to: graph[node]){
        if(to.fi == par) continue;
        dfs(to.fi, node, h+to.se);
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);  cout.tie(NULL);
    cin >> nodes >> d;
    last.resize(nodes);
    for(int i=0, a, b, c; i<nodes-1; i++){
        cin >> a >> b >> c;
        --a; --b;
        graph[a].pb({b, c});
        graph[b].pb({a, c});
    }
    for(int i=0, a , b; i<d; i++){
        cin >> a >> b;
        --a; --b;
        ban.pb({a, b});
    }
    process(0, -1, 0);
    dfs(0, -1, 0);
    n = height.size();
    construct();
    res[0][0] = dis[ban[0].se] + (dis[ban[0].se]+dis[ban[0].fi] - (2*dis[lca(ban[0].fi, ban[0].se)]));
    res[1][0] = dis[ban[0].fi] + (dis[ban[0].se]+dis[ban[0].fi] - (2*dis[lca(ban[0].fi, ban[0].se)]));
    for(int i=1; i<d; i++){
        int x = ban[i].fi, y = ban[i].se, prex = ban[i-1].fi, prey = ban[i-1].se;
        ll ndis = dis[x] + dis[y] - (2*dis[lca(x, y)]);
        // ends on x
        res[0][i] = ndis + (dis[y] + dis[prex] - (2*dis[lca(y, prex)])) + res[0][i-1];
        res[0][i] = min(res[0][i], ndis + (dis[y] + dis[prey] - (2*dis[lca(y, prey)])) + res[1][i-1]);
        // ends on y
        res[1][i] = ndis + (dis[x] + dis[prex] - (2*dis[lca(x, prex)])) + res[0][i-1];
        res[1][i] = min(res[1][i], ndis + (dis[x] + dis[prey] - (2*dis[lca(x, prey)])) + res[1][i-1]);
    }
    cout << min(res[0][d-1], res[1][d-1]) << "\n";
    return 0;
}
