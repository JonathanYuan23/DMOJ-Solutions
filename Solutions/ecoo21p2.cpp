#pragma GCC optimize "Ofast"
#include <bits/stdc++.h>
using namespace std; using pii = pair<int, int>;  using piii = pair<int, pii>;  using piiii = pair<pii, pii>;  using vi = vector<int>;  using vii = vector<pii>;  using viii = vector<piii>;  using viiii = vector<piiii>; using ll = long long; using ull = unsigned long long; 
#define frein freopen("input.txt", "r", stdin)
#define freout freopen("output.txt", "w", stdout)
#define fi first
#define se second
#define pb push_back
#define pf push_front
#define ppb pop_back
#define LSB(x) (x & (-x))
#define sz(x) (int)(x.size())
#define odd(x) (x % 2)

const int MOD = 1000000007, INF = 0x3f3f3f3f, MX = 20, IMX = INT_MAX, IMN = INT_MIN;
const long long LLMX = LONG_LONG_MAX, LLMN = LONG_LONG_MIN;
const char nl = '\n';

int n;
string s;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL);  cout.tie(NULL); 
    cin >> s;
    n = sz(s) - 1;
    int l = 0, r = 0;
    while(1){
        if(r == n){
            for(int i=l; i<=r; i++) cout << s[i];
            cout << ' ';
            break;
        }
        else if(s[r] == 'A'){
            if(s[r+1] != 'A'){
                r++;
            }
            else{
                for(int i=l; i<=r; i++) cout << s[i];
                cout << ' ';     
                r++; l = r;
            }
        }
        else{
            if(s[r+1] == 'A'){
                r++;
            }
            else{
                for(int i=l; i<=r; i++) cout << s[i];
                cout << ' ';     
                r++; l = r;
            }            
        }
    }
    cout << nl;
    
    return 0;
}
