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
#define MAX 10
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
int fingers[MAX];

void init(){
    mapping['1'] = mapping['q'] = mapping['a'] = mapping['z'] = 0;
    mapping['2'] = mapping['w'] = mapping['s'] = mapping['x'] = 1;
    mapping['3'] = mapping['e'] = mapping['d'] = mapping['c'] = 2;
    mapping['4'] = mapping['r'] = mapping['f'] = mapping['v'] = mapping['5'] = mapping['t'] = mapping['g'] = mapping['b'] = 3;
    mapping['6'] = mapping['y'] = mapping['h'] = mapping['n'] = mapping['7'] = mapping['u'] = mapping['j'] = mapping['m'] = 4;
    mapping['8'] = mapping['i'] = mapping['k'] = mapping[','] = 5;
    mapping['9'] = mapping['o'] = mapping['l'] = mapping['.'] = 6;
    mapping['0'] = mapping['p'] = mapping[';'] = mapping['/'] = mapping['-'] = mapping['['] = mapping['\''] = mapping['='] = mapping[']'] = 7;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL);  cout.tie(NULL);
    string s;
    cin >> s;
    init();
    for(auto c: s){
        if(isalpha(c)) fingers[mapping[tolower(c)]]++;
        else fingers[mapping[c]]++;
    }
    for(int i=0; i<8; i++) cout << fingers[i] << '\n';

    return 0;
}
