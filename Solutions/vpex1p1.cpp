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
    vi a(5), b(5);
    for(int i=0; i<5; i++) cin >> a[i];
    for(int i=0; i<5; i++) cin >> b[i];
    sort(a.begin(), a.end()); sort(b.begin(), b.end());
    cout << max(accumulate(a.begin(), a.end(), 0)-a[0], accumulate(b.begin(), b.end(), 0)-b[0]);
    return 0;
}
