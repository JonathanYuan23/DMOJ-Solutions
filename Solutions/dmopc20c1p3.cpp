#pragma GCC optimize "Ofast"
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MOD 1000000009
#define p 31
#define INF 0x3f3f3f3f
#define MAXN 500005
#define pb push_back
#define LSB(S) (S & (-S))
typedef vector<int> vi;
typedef vector<vector<int>> vii;

ll arr[MAXN];

int main()
{
    ll n, mx=INT_MIN, ind=-1, ans=0;  cin >> n;

    for(int i=0; i<n; i++){
        cin >> arr[i];
        if(arr[i]>mx){
            mx=arr[i];
            ind=i;
        }
    }
    mx=INT_MIN;
    for(int i=0; i<ind; i++){
        if(arr[i]>mx){
            mx=arr[i];
        } else if(arr[i]<mx){
            ans+=mx-arr[i];
        }
    }
    mx=INT_MIN; 
    for(int i=n-1; i>ind; i--){
        if(arr[i]>mx){
            mx=arr[i];
        } else if(arr[i]<mx){
            ans+=mx-arr[i];
        }
    }

    cout << ans << "\n";
    
    return 0;
}
