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
#define MAX 200005
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

int n, p[MAX], w[MAX], d[MAX];

ll cost(int x){
    long long sum = 0;
    for(int i=0; i<n; i++){
        if(x < p[i] - d[i]) sum += (ll) (p[i] - d[i] - x) * w[i];
        if(x > p[i] + d[i]) sum += (ll) (x - (p[i] + d[i])) * w[i];
    }
    return sum;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL);  cout.tie(NULL);
    cin >> n;
    for(int i=0; i<n; i++) cin >> p[i] >> w[i] >> d[i];
    int left = 0, right = 1e9 + 1;
    while(left < right){
        int mid = (left + right) / 2;
        if(cost(mid) < cost(mid + 1)) right = mid;
        else left = mid + 1;
    }
    cout << cost(left) << nl;

    return 0;
}
