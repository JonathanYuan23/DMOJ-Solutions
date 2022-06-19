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
#define MAX 1000005
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

umap<int, int> idx;
int n, m;
vi sequence, lis;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL);  cout.tie(NULL);
    cin >> n;
    for(int i=1, a; i<=n; i++){
        cin >> a;
        idx[a] = i;
    }
    cin >> m;
    for(int i=1, a; i<=m; i++){
        cin >> a;
        if(idx.count(a)) sequence.pb(idx[a]);
    }
    for(int i=0; i<sz(sequence); i++){
        int j = (lower_bound(lis.begin(), lis.end(), sequence[i])) - lis.begin();
        if(j >= sz(lis)) lis.pb(sequence[i]);
        else lis[j] = sequence[i];
    }
    cout << sz(lis) << nl;
    
    return 0;
}
