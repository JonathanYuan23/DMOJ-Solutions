#include <bits/stdc++.h>
using namespace std; 

#pragma GCC optimize "Ofast"
#define ll long long
#define MOD 1e9+7
#define fi first
#define se second
#define INF 0x3f3f3f3f
#define MAXN 30
#define pb push_back
#define LSB(S) (S & (-S))
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<piii> viii;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);  cout.tie(NULL);
    int lx = INT_MAX, rx = INT_MIN, ty = INT_MIN, by = INT_MAX, x, y;
    int n; cin >> n;
    while(n--){
        cin >> x >> y;
        lx = min(lx, x); rx = max(rx, x); ty = max(ty, y); by = min(by, y);
    }
    cout << ((rx-lx) + (ty-by))*2 << "\n";
    
    return 0;
}
