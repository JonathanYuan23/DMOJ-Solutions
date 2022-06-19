#include <bits/stdc++.h>
using namespace std; 

#pragma GCC optimize "Ofast"
#define ll long long
#define MOD 1000000007
#define fi first
#define se second
#define INF 0x3f3f3f3f
#define MAXN 1005
#define pb push_back
#define LSB(S) (S & (-S))
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<piii> viii;

int arr[MAXN];
vii res;

bool comp(pii a, pii b){
    if(a.se==b.se) return a.fi>b.fi;
    return a.se>b.se;
}

void findMax(int start, int freq){
    int mx=INT_MIN;
    for(int i=1; i<res.size(); i++){
        if(res[i].se!=freq) break;
        mx = max(mx, abs(start-res[i].fi));
    }
    cout << mx << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);  cout.tie(NULL);
    int n; cin >> n;
    for(int i=0, r; i<n; i++){
        cin >> r;
        arr[r]++;
    }
    for(int i=0; i<MAXN; i++) if(arr[i]>0) res.pb({i, arr[i]});
    sort(res.begin(), res.end(), comp);
    if(res[0].se!=res[1].se) findMax(res[0].fi, res[1].se);
    else findMax(res[0].fi, res[0].se);

    return 0;
}
