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
#define INF 0x3f3f3f3f3f3f3f3f
#define MAX 1000000005
#define pb push_back
#define LSB(S) (S & (-S))
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<pii, pii> piiii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<piii> viii;
typedef vector<piiii> viiii;

unordered_map<int, ll> dp;
int N;

ll go(int weight){
    if(weight<=2) return 1;
    if(dp.count(weight)) return dp[weight];
    ll ans = 0, currDivisor = weight, currWeight = 1;
    while(currDivisor>=2){
        int temp = (weight/currWeight) - (weight/(currWeight+1));
        ans += temp * go(currWeight);
        currDivisor -= temp;
        currWeight = weight / currDivisor;
    }
    return dp[weight] = ans;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL);  cout.tie(NULL);
    cin >> N;
    cout << go(N);

    return 0;
}
