#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize "Ofast"
#define ll long long
#define ull unsigned long long
#define MOD 1e9+7
#define fi first
#define se second
#define INF 0x3f3f3f3f
#define MAX 805
#define pb push_back
#define LSB(S) (S & (-S))
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<piii> viii;

int n, m, p[MAX];
pii b[MAX];

int findSet(int i){ 
    return (p[i] == i) ? i : (p[i] = findSet(p[i])); 
}

bool isSameSet(int i, int j){ 
    return findSet(i) == findSet(j); 
}

void unionSet(int i, int j) { 
    if(!isSameSet(i, j)){
        int x = findSet(i), y = findSet(j);
        p[y] = x;
    }
}

double dist(int x1, int y1, int x2, int y2){
    return (double)sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);  cout.tie(NULL);
    cin >> n;
    for(int i=1; i<=n; i++) cin >> b[i].fi >> b[i].se;
    for(int i=1; i<=n; i++) p[i] = i;
    cin >> m;
    for(int i=1, x, y; i<=m; i++){
        cin >> x >> y;
        unionSet(x, y);
    }
    vector<pair<double, pair<int, int>>> edges;
    vii nodes;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(i==j) continue;
            edges.pb({dist(b[i].fi, b[i].se, b[j].fi, b[j].se), {i, j}});
        }
    }
    sort(edges.begin(), edges.end());
    double cost = 0;
    for(auto E: edges){
        int u = E.se.fi, v = E.se.se; 
        double c = E.fi;
        if(!isSameSet(u, v)){
            cost += c;
            unionSet(u, v);
            nodes.pb({u, v});
        }
    }
    cout << fixed << setprecision(2) << cost << '\n';
    for(auto E: nodes) cout << E.fi << " " << E.se << '\n';
    
    return 0;
}
