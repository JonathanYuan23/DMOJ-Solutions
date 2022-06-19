#include <bits/stdc++.h>
using namespace std; 

#pragma GCC optimize "Ofast"
#define ll long long
#define MOD 1000000007
#define fi first
#define se second
#define INF 0x3f3f3f3f
#define MAXN 30
#define pb push_back
#define LSB(S) (S & (-S))
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<piii> viii;

int pascals[MAXN][MAXN];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);  cout.tie(NULL);
    memset(pascals, -1, sizeof pascals);
    pascals[1][1] = 1;
    for(int i=2; i<=25; i++){
        for(int j=1; j<=i; j++){
            if(j==1||j==i) pascals[i][j]=1;
            else pascals[i][j] = pascals[i-1][j-1] + pascals[i-1][j];
        } 
    }
    int n; cin >> n;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=i; j++){
            cout << pascals[i][j] << " ";
        }   cout << "\n";
    }
    
    return 0;
}
