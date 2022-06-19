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

unordered_map<char, char> decryptions;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);  cout.tie(NULL);
    string s1, s2, s3;
    getline(cin, s1); getline(cin, s2); getline(cin, s3);
    for(int i=0; i<s1.length(); i++){
        decryptions[s2[i]] = s1[i];
    }
    for(int i=0; i<s3.length(); i++){
        if(!decryptions[s3[i]]) cout << ".";
        else cout << decryptions[s3[i]];
    }   cout << "\n";
    
    return 0;
}
