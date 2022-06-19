#include <bits/stdc++.h>
using namespace std; 

#pragma GCC optimize "Ofast"
#define ll long long
#define MOD 1000000007
#define fi first
#define se second
#define INF 0x3f3f3f3f
#define MAXN 100005
#define pb push_back
#define LSB(S) (S & (-S))
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<piii> viii;

int vals[MAXN];
vi groups;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);  cout.tie(NULL);
    vals[1]=1;
    for(int i=2; i<=MAXN; i++) vals[i] = (i+vals[i-1])%MOD;
    int n, sz=1; cin >> n;
    string s; cin >> s;
    char prev = tolower(s[0]), curr;
    for(int i=1; i<n; i++){
        cin >> s;
        curr = tolower(s[0]);
        if(curr==prev) sz++;
        else{
            groups.pb(sz);
            sz=1;
        }
        prev=curr;
    }
    groups.pb(sz);
    ll ans=0;
    for(auto x: groups) ans = (ans+vals[x])%MOD;
    cout << ans << "\n";

    return 0;
}
