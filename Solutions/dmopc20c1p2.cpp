#pragma GCC optimize "Ofast"
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MOD 1000000009
#define p 31
#define INF 0x3f3f3f3f
#define MAXN 1000005
#define pb push_back
#define LSB(S) (S & (-S))
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vii;

int arr[MAXN], N, D, A=1;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL);  cout.tie(NULL);
    cin >> N >> D;
    for(int i=1; i<=N; i++) cin >> arr[i];
    int n, f, s;
    for(int i=0; i<D; i++){
        cin >> n;
        f=0; s=0;
        for(int j=A; j<=A+n-1; j++) f+=arr[j];
        for(int j=A+n; j<=N; j++) s+=arr[j];
        (f>=s)?A+=n:N=A+n-1;
        cout << ((f>=s)?f:s) << "\n";
    }

    return 0;
}
