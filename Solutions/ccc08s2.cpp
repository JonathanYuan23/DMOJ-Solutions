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

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL);  cout.tie(NULL);
    int n, ans; 
    double bigr, smallr;
    cin >> n;
    while(n!=0){
        bigr=(double)n*n;
        ans=0;
        for(int i=1; i<=n; i++){
            smallr=(double)i*i;
            ans+=(int)sqrt(bigr-smallr)+1;
        }
        ans=4*ans+1;
        cout << ans << "\n";
        cin >> n;
    }

    return 0;
}
