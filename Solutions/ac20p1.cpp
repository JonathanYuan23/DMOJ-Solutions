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
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<pii, pii> piiii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<piii> viii;
typedef vector<piiii> viiii;  

ll t, arr[5];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);  cout.tie(NULL);
    cin >> t;
    while(t--){
        cin >> arr[0] >> arr[1] >> arr[2];
        sort(arr, arr+3);
        if(arr[2] * arr[2] < arr[0] * arr[0] + arr[1] * arr[1]) cout << "A\n";
        else if(arr[2] * arr[2] == arr[0] * arr[0] + arr[1] * arr[1]) cout << "R\n";
        else if(arr[2] * arr[2] > arr[0] * arr[0] + arr[1] * arr[1]) cout << "O\n";
    }
    
    return 0;
};
