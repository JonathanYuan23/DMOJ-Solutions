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

int N, M, J;

struct Dry{
    int inch, time;
} dries[MAX];

bool operator<(const Dry &a, const Dry &b){
    return a.time < b.time;
}

int b_search(int t){
    int lo = 0, high = M-1, best = -1;
    while(lo <= high){
        int mid = (lo + high) / 2;
        if(dries[mid].time <= t){
            lo = mid + 1;
            best = mid;
        }
        else high = mid - 1;
    }
    return best;
}

bool ok(int t){
    int lim = b_search(t);
    if(lim == -1) return (!N || J >= (N + 1));
    vi gaps;
    for(int i=0; i<=lim; i++) gaps.pb(dries[i].inch);
    gaps.pb(0);
    gaps.pb(N + 1);
    sort(gaps.begin(), gaps.end());
    for(int i=1; i<sz(gaps); i++) if(gaps[i] - gaps[i-1] > J) return 0;
    return 1;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL);  cout.tie(NULL);
    cin >> N >> M >> J;
    for(int i=0; i<M; i++) cin >> dries[i].inch >> dries[i].time;
    sort(dries, dries + M);
    int lo = 0, high = 1e6 + 5, best = -1;
    while(lo <= high){
        int mid = (lo + high) / 2;
        if(ok(mid)){
            high = mid - 1;
            best = mid;
        }
        else lo = mid + 1;
    }
    cout << best << nl;
    
    return 0;
}
