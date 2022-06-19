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

int psa[1000006][26];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);  cout.tie(NULL);
    string s; getline(cin, s);
    psa[0][s[0]-'a']++;
    for(int i=1; i<s.size(); i++){
        for(int j=0; j<26; j++) psa[i][j] = psa[i-1][j];
        if(s[i]==' ') continue;
        psa[i][s[i]-'a']++;
    }
    int q; cin >> q;
    while(q--){
        int a, b; char c;
        cin >> a >> b >> c;
        --a; --b;
        cout << ((!a) ? psa[b][c-'a'] : psa[b][c-'a'] - psa[a-1][c-'a']) << '\n';
    }
    return 0;
}
