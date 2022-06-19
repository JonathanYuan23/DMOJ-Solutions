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
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<pii, pii> piiii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<piii> viii;
typedef vector<piiii> viiii;  

ll n, q, freq[MAX];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);  cout.tie(NULL);
    cin >> n >> q;
    for(int i=0, a; i<n; i++){
        cin >> a;
        freq[a]++;
    }
    for(int i=0, op, x; i<q; i++){
        cin >> op >> x;
        if(op == 1){
            freq[(int)floor((double)(x) / 2)] += freq[x];
            freq[(int)ceil((double)(x) / 2)] += freq[x];
            freq[x] = 0;
        }
        else cout << freq[x] << nl;
    }
    
    return 0;
};
