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
#define MAX 1000005
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

vi ans;
vector<double> fact;

int solve(const string &s, const int &len){
    fact.pb(0);
    ans.pb(1);
    double i = 2.0;
    for(; ans.back() <= MAX; i++){
        fact.pb(log10(i) + fact.back());
        ans.pb((int)floor(fact.back())+1);
        if(ans.back() == len) return i;
    }
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL);  cout.tie(NULL);
    string s;
    cin >> s;
    if(s.length() <= 10){
        ll num = stoi(s), temp = 1;
        for(int i=1; i<=16; i++){
            temp *= i;
            if(temp == num){
                cout << i << '\n';
                return 0;
            }
        }
    }
    else cout << solve(s, s.length()) << '\n';
    
    return 0;
}
