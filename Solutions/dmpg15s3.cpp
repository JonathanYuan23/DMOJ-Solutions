/*

ICPC SWERC 2017 G - Cordon Bleu

Idea:
each edge will either be between a restaurant and a winery, or a winery and a courier
couriers and restaurants can only be attached to wineries, not each other
calculate the manhattan distances from each winery to each restaurant, also consider double edges where the courier goes from the restaurant to the winery and back to the restaurant
calculate the manhattan distances from each courier to each winery
now for each courier consider which winery he should go to first, the minimum cost for this courier to deliver all the wines starting from wine W is dist[courier][W] + dist[W][restaurant] + doubleDist[restaurant][allOtherWineries]
do this for each courier and you have your answer
however this is only assuming that one courier will be used
we need to pick a subset of couriers and edges they will take so that the cost is as small as possible, because of the huge time and memory limit, and the N <= 1000 which means a bitmask won't work, backtracking should do the trick

*/
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
#define sz(x) (int)(x.size())
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<pii, pii> piiii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<piii> viii;
typedef vector<piiii> viiii;

int N, M, flowers[MAX], pairs[MAX];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL);  cout.tie(NULL);
    cin >> N;
    for(int i=1; i<=N; i++) cin >> flowers[i];
    cin >> M;
    ll ans = 0;
    for(int i=1, f, c; i<=M; i++){
        cin >> f >> c;
        if(max(flowers[f], flowers[f+1]) > flowers[f] + flowers[f+1] - c) ans += max(flowers[f], flowers[f+1]);
        else ans += flowers[f] + flowers[f+1] - c;
        pairs[f] = pairs[f+1] = 1;
    }
    for(int i=1; i<=N; i++) if(!pairs[i]) ans += flowers[i];
    cout << ans << '\n';

    return 0;
};
