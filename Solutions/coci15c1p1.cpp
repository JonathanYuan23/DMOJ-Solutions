#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize "Ofast"
#define frein freopen("input.txt", "r", stdin)
#define freout freopen("output.txt", "w", stdout)
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define fi first
#define se second
#define INF 0x3f3f3f3f
#define MAX 30
#define pb push_back
#define LSB(x) (x & (-x))
#define sz(x) (int)(x.size())
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<pii, pii> piiii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<piii> viii;
typedef vector<piiii> viiii;

unordered_map<char, int> mapping;
int freq[MAX][MAX];

void solve(){
    string s;
    cin >> s;
    for(int i=0; i<sz(s); i++){
        if(isalpha(s[i])){
            string numeric = "";
            for(int j=i+1; j<sz(s) && isdigit(s[j]); j++) numeric += s[j];
            freq[s[i]-'A'][stoi(numeric)]++;
            mapping[s[i]]++;
            if(freq[s[i]-'A'][stoi(numeric)] > 1){
                cout << "GRESKA\n";
                return;
            }
        }
    }
    cout << 13 - mapping['P'] << ' ' << 13 - mapping['K'] << ' ' << 13 - mapping['H'] << ' ' << 13 - mapping['T'] << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL);  cout.tie(NULL);
    solve();

    return 0;
}
