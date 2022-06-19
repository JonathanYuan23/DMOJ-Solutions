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

int m, costs[MAX][MAX], p[MAX];
vi corners[MAX][MAX];
viii edges, outside_edges;

void initialize(){
    for(int i=1; i<=1000; i++) p[i] = i;
}

void unionSet(int i, int j){
    p[i] = j;
}

int findSet(int i){ 
    return (p[i] == i) ? i : (p[i] = findSet(p[i])); 
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL);  cout.tie(NULL);
    cin >> m;
    for(int i=1, n; i<=m; i++){
        cin >> n;
        vi temp(n);
        for(int j=0; j<n; j++) cin >> temp[j];
        for(int j=0, u, v, e; j<n; j++){
            u = temp[j], v = temp[(j + 1) % n];
            if(v < u) swap(u, v);
            cin >> e;
            corners[u][v].pb(i);
            costs[u][v] = e;
        }
    }
    for(int i=1; i<=1000; i++){
        for(int j=1; j<=1000; j++){
            if(sz(corners[i][j]) == 1) outside_edges.pb({costs[i][j], {corners[i][j][0], 500}});
            else if(sz(corners[i][j]) == 2) edges.pb({costs[i][j], {corners[i][j][0], corners[i][j][1]}});
        }
    }
    int ans = IMX, cur_ans = 0;
    sort(edges.begin(), edges.end());
    initialize();
    for(auto &E: edges){
        int u = findSet(E.se.fi), v = findSet(E.se.se), c = E.fi;
        if(u != v){
            cur_ans += c;
            unionSet(u, v);
        }
    }
    ans = min(ans, cur_ans);
    for(auto &E: outside_edges) edges.pb(E);
    cur_ans = 0;
    sort(edges.begin(), edges.end());
    initialize();
    for(auto &E: edges){
        int u = findSet(E.se.fi), v = findSet(E.se.se), c = E.fi;
        if(u != v){
            cur_ans += c;
            unionSet(u, v);
        }
    }
    cout << min(ans, cur_ans) << nl;

    return 0;
}
