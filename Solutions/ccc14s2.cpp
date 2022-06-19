#include <bits/stdc++.h>
using namespace std; 

#pragma GCC optimize "Ofast"
#define ll long long
#define MOD 1000000007
#define fi first
#define se second
#define INF 0x3f3f3f3f
#define MAXN 35
#define pb push_back
#define LSB(S) (S & (-S))
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<piii> viii;

unordered_map<string, set<string>> p;
string p1[MAXN], p2[MAXN];

bool check(){
    for(auto person: p){
        if(person.second.find(person.first)!=person.second.end()) return 0;
        for(auto partner: person.second) if(p[partner].find(person.first)==p[partner].end()) return 0;
    }
    return 1;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);  cout.tie(NULL);
    int n; cin >> n;
    for(int i=0; i<n; i++) cin >> p1[i];
    for(int i=0; i<n; i++) cin >> p2[i];
    for(int i=0; i<n; i++) p[p2[i]].insert(p1[i]);
    cout << ((check()) ? "good\n" : "bad\n");
    return 0;
}
