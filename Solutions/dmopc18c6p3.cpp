#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize "Ofast"
#define ll long long
#define ull unsigned long long
#define MOD 1e9+7
#define fi first
#define se second
#define INF 0x3f3f3f3f
#define MAX 200005
#define pb push_back
#define LSB(S) (S & (-S))
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<piii> viii;

int n, m, p[MAX], ranking[MAX]; 

int findSet(int i) { 
    return (p[i] == i) ? i : (p[i] = findSet(p[i])); 
}

void unionSet(int u, int v){
    if(ranking[u] > ranking[v]) p[v] = u;
    else{
        p[u] = v;
        if(ranking[u] == ranking[v]) ranking[v]++;
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);  cout.tie(NULL);
    cin >> n >> m;
    for(int i=1; i<=n; i++) p[i] = i;
    int ans = 0;
    for(int i=0; i<m; i++){
        int u, v, x, y;
        cin >> u >> v;
        x = findSet(u); y = findSet(v);
        if(x == y) ans++;
        else unionSet(x, y);
    }
    cout << ((ans==0 || ans==1) ? "YES\n" : "NO\n");
        
    return 0;
}
