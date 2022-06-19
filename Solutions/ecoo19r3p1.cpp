#include <bits/stdc++.h>
using namespace std; 

#pragma GCC optimize "Ofast"
#define ll long long
#define MOD 1000000007
#define fi first
#define se second
#define INF 0x3f3f3f3f
#define MAXN 1000005
#define pb push_back
#define LSB(S) (S & (-S))
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<piii> viii;

bool arr[MAXN];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);  cout.tie(NULL);
    for(int i=0; i<10; i++){
        memset(arr, 0, sizeof arr);
        int n, ans=0, mx=INT_MIN, num; 
        cin >> n;
        for(int i=0; i<n; i++){
            cin >> num;
            mx=max(mx, num);
            arr[num]=1;
        }
        for(int i=1; i*2<=mx; i++){
            if(arr[i]){
                for(int j=i*2; j<=mx; j+=i)
                    if(arr[j]) ans++;
            }
        }
        cout << ans << "\n";
    }
    
    return 0;
}
