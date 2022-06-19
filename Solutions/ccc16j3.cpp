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

string s;

bool palindrome(int l, int r){
    if(s[l]!=s[r]) return 0;
    if(r-l<=1) return 1;
    return palindrome(l+1, r-1);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);  cout.tie(NULL);
    cin >> s;
    int ans=-1;
    for(int i=0; i<s.length(); i++){
        for(int len=1; len<=s.length()-i; len++){
            if(palindrome(i, i+len-1)) ans=max(ans, len);
        }
    }
    cout << ans << "\n";
    
    return 0;
}
