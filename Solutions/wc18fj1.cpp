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

int n;
unordered_map<int, int> freq;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL);  cout.tie(NULL);
    cin >> n;
    for(int i=0, w; i<n; i++){
        cin >> w;
        freq[w]++;
    }
    int mx1 = 0, mx2 = 0;
    for(auto width: freq){
        if(width.se >= mx1){
            mx2 = mx1;
            mx1 = width.se;
        }
        else if(width.se > mx2) mx2 = width.se;
    }
    cout << mx1 + mx2 << '\n';
    return 0;
};
