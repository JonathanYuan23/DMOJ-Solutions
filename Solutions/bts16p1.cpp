#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize "Ofast"
#define ll long long
#define ull unsigned long long
#define MOD 1e9+7
#define fi first
#define se second
#define INF 0x3f3f3f3f
#define MAX 10005
#define pb push_back
#define LSB(S) (S & (-S))
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<piii> viii;

int dp[MAX][1000];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);  cout.tie(NULL);
    string s; getline(cin, s);
    int u = 0, l = 0;
    for(auto x: s) if(x != ' ') (isupper(x)) ? u++ : l++;
    if(u > l) transform(s.begin(), s.end(), s.begin(), ::toupper);
    if(u < l) transform(s.begin(), s.end(), s.begin(), ::tolower);
    cout << s << '\n';
        
    return 0;
}
