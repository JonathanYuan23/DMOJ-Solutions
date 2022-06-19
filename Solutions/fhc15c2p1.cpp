#pragma GCC optimize "Ofast"
#include <bits/stdc++.h>
using namespace std; using pii = pair<int, int>;  using piii = pair<int, pii>;  using piiii = pair<pii, pii>;  using vi = vector<int>;  using vii = vector<pii>;  using viii = vector<piii>;  using viiii = vector<piiii>; using ll = long long; using ull = unsigned long long; 
#define frein freopen("input.txt", "r", stdin)
#define freout freopen("output.txt", "w", stdout)
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define LSB(x) (x & (-x))
#define sz(x) (int)(x.size())
#define ms(a, b) memset(a, b, sizeof a)

const int MOD = 1000000007, INF = 0x3f3f3f3f, MX = 50005, IMX = INT_MAX, IMN = INT_MIN;
const long long LLMX = LONG_LONG_MAX, LLMN = LONG_LONG_MIN;
const char nl = '\n';

int t, n;

bool solve(int start, deque<int> I, deque<int> F){
    if(start){ F.pb(I.back()); I.ppb(); }
    else{ F.pb(I.front()); I.ppf(); }
    // back is top, front is bottom
    while(sz(I)){
        if(I.back() == F.back() + 1){
            F.pb(I.back());
            I.ppb();
        } else if(I.back() == F.front() - 1){
            F.pf(I.back());
            I.ppb();           
        } else{
            if(I.front() == F.back() + 1){
                F.pb(I.front());
                I.ppf();
            } else if(I.front() == F.front() - 1){
                F.pf(I.front());
                I.ppf();
            } else return 0;
        }
    }
    return 1;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);  cout.tie(0);
    cin >> t;
    for(int tc=1; tc<=t; tc++){
        deque<int> I, F;
        cin >> n; I.resize(n);
        for(int i=0; i<n; i++) cin >> I[i];
        if(solve(0, I, F) || solve(1, I, F)) cout << "Case #" << tc << ": yes\n";
        else cout << "Case #" << tc << ": no\n";
    }
    return 0;
}
