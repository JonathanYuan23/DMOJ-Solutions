#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize "Ofast"
#define frein freopen("input.txt", "r", stdin)
#define freout freopen("output.txt", "w", stdout)
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define nl '\n'
#define fi first
#define se second
#define INF 0x3f3f3f3f
#define MAX 200005
#define IMX INT_MAX
#define IMN INT_MIN
#define LLMX LONG_LONG_MAX
#define LLMN LONG_LONG_MIN
#define pb push_back
#define pf push_front
#define LSB(x) (x & (-x))
#define sz(x) (ll)(x.size())
#define umap unordered_map
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<pii, pii> piiii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<piii> viii;
typedef vector<piiii> viiii;  

int n, w, d, dis[MAX], idx[MAX], seq[MAX];
vi graph[MAX];
set<pii> res;

void bfs(){
    memset(dis, INF, sizeof dis);
    dis[n] = 0;
    queue<int> q;
    q.push(n);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(auto &to: graph[u]){
            if(dis[to] == INF){
                dis[to] = dis[u] + 1;
                q.push(to);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL);  cout.tie(NULL);
    cin >> n >> w >> d;
    for(int i=0, u, v; i<w; i++){
        cin >> u >> v;
        graph[v].pb(u);
    }
    for(int i=0; i<n; i++){
        cin >> seq[i+1];
        idx[seq[i+1]] = i;
    }
    bfs();
    for(int i=1; i<=n; i++) res.insert({idx[i] + dis[i], i});
    for(int i=0, u, v; i<d; i++){
        cin >> u >> v;
        res.erase({idx[seq[u]] + dis[seq[u]], seq[u]});
        res.erase({idx[seq[v]] + dis[seq[v]], seq[v]});
        swap(idx[seq[u]], idx[seq[v]]);
        swap(seq[u], seq[v]);
        res.insert({idx[seq[u]] + dis[seq[u]], seq[u]});
        res.insert({idx[seq[v]] + dis[seq[v]], seq[v]});
        cout << (*res.begin()).fi << nl;
    }

    return 0;
}
