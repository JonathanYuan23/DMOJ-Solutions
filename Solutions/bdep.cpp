#pragma GCC optimize "Ofast"
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MOD 1000000009
#define fi first
#define se second
#define INF 0x3f3f3f3f
#define MAXN 500005
#define pb push_back
#define LSB(S) (S & (-S))
typedef pair<int, int> pii;
typedef pair<pair<int, int>, int> piii;

ll Y, T, P;

bool valid(ll N){
    ll sum=0;
    for(int i=0; i<Y; i++){
        sum=(sum+N)*(P+100)/100;
        if(sum>=T) return true;
    }
    
    return false;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL);  cout.tie(NULL);
    cin >> P >> Y >> T;
    ll lo=0, high=T, mid, ans=LONG_LONG_MAX;
    while(lo<=high){
        mid=lo+(high-lo)/2;
        if(valid(mid)){
            ans=min(ans, mid);
            high=mid-1;
        } else {
            lo=mid+1;
        }
    }
    cout << lo << "\n";

    return 0;
}
