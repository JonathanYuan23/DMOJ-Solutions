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
#define IMN INT_MIN
#define LLMX LONG_LONG_MAX
#define LLMN LONG_LONG_MIN
#define pb push_back
#define pf push_front
#define LSB(x) (x & (-x))
#define sz(x) (int)(x.size())
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<pii, pii> piiii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<piii> viii;
typedef vector<piiii> viiii;

int N, M, K, p[MAX];
string s;

int findSet(int i) { 
    return (p[i] == i) ? i : (p[i] = findSet(p[i])); 
}

bool isSameSet(int i, int j) { 
    return findSet(i) == findSet(j); 
}

void unionSet(int i, int j){
    int x = findSet(i), y = findSet(j);
    if(x != y) p[x] = y;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL);  cout.tie(NULL);
    cin >> N >> M >> K >> s;
    for(int i=1; i<=N; i++) p[i] = i;
    for(int i=0, u, v; i<M; i++){
        cin >> u >> v;
        if(s[u-1] == s[v-1]) unionSet(u, v);
    }
    int ans = 0;
    for(int i=0, u, v; i<K; i++){
        cin >> u >> v;
        if(isSameSet(u, v)) ans++;
    }
    cout << ans << '\n';
    
    return 0;
};
