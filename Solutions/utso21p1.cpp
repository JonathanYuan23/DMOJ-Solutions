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
#define MAX 1050005
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

ll n;

ll calc(int num){
    ll ans = 0;
    if(num % 2 == 0){
        ll temp = (num / 2) + 1, temp2 = (num / 2);
        ans = (temp * temp) + (temp2 * temp2);
    }
    else{
        ll temp = (num / 2) + 1;
        ans = temp * (num + 1);
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);  cout.tie(NULL);
    cin >> n;
    ll lo = 1, high = 1000000, best = -1;
    while(lo <= high){
        ll mid = (lo + high) / 2;
        if(calc(mid) >= n){
            best = mid;
            high = mid - 1;
        }
        else lo = mid + 1;
    }
    cout << best << nl;
    return 0;
};
