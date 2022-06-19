#include <bits/stdc++.h>
using namespace std; 

#pragma GCC optimize "Ofast"
#define ll long long
#define MOD 1000000007
#define fi first
#define se second
#define INF 0x3f3f3f3f
#define MAXN 35
#define pb push_back
#define LSB(S) (S & (-S))
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<piii> viii;

int arr[MAXN];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);  cout.tie(NULL);
    int T, C; cin >> T >> C;
    for(int i=0; i<C; i++) cin >> arr[i];
    sort(arr, arr+C);
    int time=0, ans=0;
    for(int i=0; i<C; i++){
        if(time+arr[i]<=T){ans++; time+=arr[i];}
        else break;
    }
    cout << ans << "\n";
    return 0;
}
