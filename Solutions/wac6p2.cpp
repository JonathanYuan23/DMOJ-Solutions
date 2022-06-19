#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize "Ofast"
#define frein freopen("input.txt", "r", stdin)
#define freout freopen("output.txt", "w", stdout)
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
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
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<pii, pii> piiii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<piii> viii;
typedef vector<piiii> viiii;

int N, M, bulbs[MAX], flips[MAX], freq[MAX];

bool ok(int m){
    memset(freq, 0, sizeof freq);
    for(int i=1; i<=m && i<=M; i++) freq[flips[i]]++;
    int ans = 0;
    for(int i=1; i<=N; i++){
        if(!bulbs[i]){
            if(freq[i]%2!=0) ans++;
        }
        else{
            if(freq[i]%2==0) ans++;
        }
    }
    return ans <= m;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL);  cout.tie(NULL);
    cin >> N >> M;
    for(int i=1; i<=N; i++) cin >> bulbs[i];
    for(int i=1; i<=M; i++) cin >> flips[i];
    int lo = 0, high = MAX * 5, best = INT_MAX;
    while(lo <= high){
        int mid = (lo + high) / 2;
        if(ok(mid)){
            best = min(best, mid);
            high = mid-1;
        }
        else{
            lo = mid + 1;
        }
    }
    cout << best << '\n';
    
    return 0;
};
