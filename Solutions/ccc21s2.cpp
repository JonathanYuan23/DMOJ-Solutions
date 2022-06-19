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
#define MAX 5000005
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

int n, m, k, even_row = 0, odd_row = 0, even_col = 0, odd_col = 0, row[MAX], col[MAX];
char c;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL);  cout.tie(NULL);
    cin >> n >> m >> k;
    for(int i=0, op; i<k; i++){
        cin >> c >> op;
        if(c == 'R') row[op]++;
        else col[op]++;
    }
    for(int i=1; i<=n; i++) ((row[i] % 2 == 0) ? even_row++ : odd_row++);
    for(int i=1; i<=m; i++) ((col[i] % 2 == 0) ? even_col++ : odd_col++);
    cout << (even_row * odd_col) + (odd_row * even_col) << nl;

    return 0;
}
