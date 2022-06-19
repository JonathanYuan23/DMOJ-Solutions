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
#define umap unordered_map
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<pii, pii> piiii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<piii> viii;
typedef vector<piiii> viiii;  

int R, C, K;

ll query(int r, int c){
    cout << "? " << r << ' ' << c << endl;
    ll ret;
    cin >> ret;
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL);  cout.tie(NULL);
    cin >> R >> C >> K;
    int r1 = 1, r2 = R, c1 = 1, c2 = C;
    while(r1 < r2 || c1 < c2){
        int rm = (r1 + r2) / 2, cm = (c1 + c2) / 2, cen = -1;
        if(r1 < r2){
            if(cen == -1) cen = query(rm, cm);
            int up = query(rm+1, cm);
            if(cen < up) r2 = rm;
            else r1 = rm + 1;
        }
        if(c1 < c2){
            if(cen == -1) cen = query(rm, cm);
            int rit = query(rm, cm+1);
            if(cen < rit) c2 = cm;
            else c1 = cm + 1;
        }
    }
    int ans = query(r1, c1);
    cout << "! " << ans << endl;
    return 0;
}
