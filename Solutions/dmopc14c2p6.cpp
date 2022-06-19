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
#define MAX 100005
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

ll N, Q, ft[MAX], ans[MAX];
vii trees;
viiii queries;

ll rsq(int b) {        
    ll sum = 0; 
    for (; b; b -= LSB(b)) sum += ft[b];
    return sum; 
}

ll rsq(int a, int b) {                    
    return rsq(b) - (a == 1 ? 0 : rsq(a - 1));
}

void adjust(int k, int v) {                 
    for (; k <= N; k += LSB(k)) ft[k] += v; 
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL);  cout.tie(NULL);
    cin >> N;
    for(int i=1, a; i<=N; i++){
        cin >> a;
        trees.pb({a, i});
    }
    cin >> Q;
    for(int i=1, a, b, q; i<=Q; i++){
        cin >> a >> b >> q;
        queries.pb({{q, i}, {a, b}});
    }
    sort(trees.begin(), trees.end());
    sort(queries.rbegin(), queries.rend());
    for(int i=0; i<sz(queries); i++){
        while(!trees.empty() && trees.back().fi >= queries[i].fi.fi){
            adjust(trees.back().se, trees.back().fi);
            trees.pop_back();
        }
        ans[queries[i].fi.se] = rsq(queries[i].se.fi + 1, queries[i].se.se + 1);
    }
    for(int i=1; i<=Q; i++) cout << ans[i] << nl;
    return 0;
}
