#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize "Ofast"
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define fi first
#define se second
#define INF 0x3f3f3f3f3f3f3f3f
#define MAX 100005
#define pb push_back
#define LSB(S) (S & (-S))
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<piii> viii;

int n, k, p[MAX];
viii edges;

int findSet(int i){ 
    return (p[i] == i) ? i : (p[i] = findSet(p[i])); 
}

bool unionS(int i, int j){
    int x = findSet(i), y = findSet(j);
    if(x==y) return 0;
    p[x] = y;
    return 1;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL);  cout.tie(NULL);
    cin >> n >> k;
    for(int i=1, c; i<=n-1; i++){
        cin >> c;
        edges.pb({c, {i, i+1}});
        if(i+k<=n) edges.pb({0, {i, i+k}});
        p[i] = i;
    }
    p[n] = n;
    sort(edges.begin(), edges.end());
    int ans = 0;
    for(auto edge: edges) if(unionS(edge.se.fi, edge.se.se)) ans += edge.fi;
    cout << ans << '\n';
    return 0;
}
