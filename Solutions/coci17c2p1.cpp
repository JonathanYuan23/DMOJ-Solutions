#include <bits/stdc++.h>
using namespace std; 

#pragma GCC optimize "Ofast"
#define ll long long
#define MOD 1000000007
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
    int n; cin >> n;
    while(n--){
        int r, c; 
        cin >> r >> c;
        cout << min((r-1) + (r-1),(c-1)+(c-1))<< "\n";
    }

    return 0;
}
