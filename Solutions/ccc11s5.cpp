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

const int MOD = 1000000007, mod = 13371337, INF = 0x3f3f3f3f, MX = 1<<25, IMX = INT_MAX, IMN = INT_MIN;
const long long LLMX = LONG_LONG_MAX, LLMN = LONG_LONG_MIN;
const char nl = '\n';

int n, bulbs;
bitset<MX> vis;
queue<pii> q;

int nstate(int state){
    int r=0, l=0;
    while(1){
        if(l==n-1){
            if((state & 1 << l) && l-r+1 >= 4){
                int mask = (1 << (l-r+1)) - 1;
                mask <<= r;
                state ^= mask;
            }
            else if(!(state & 1 << l) && (l-1)-r+1 >= 4){
                int mask = (1 << ((l-1)-r+1)) - 1;
                mask <<= r;
                state ^= mask;
            }
            break;
        }
        if(!(state & 1 << l)){
            if((l-1)-r+1 >= 4){
                int mask = (1 << ((l-1)-r+1)) - 1;
                mask <<= r;
                state ^= mask;
            }
            l++; r = l;
        }
        else{
            l++;
        }
    }
    return state;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL);  cout.tie(NULL); 
    cin >> n;
    for(int i=0, bulb; i<n; i++){cin >> bulb; bulbs += bulb * (1<<i);}
    q.push({0, bulbs});
    vis[bulbs] = 1;
    while(!q.empty()){
        int step = q.front().fi, state = q.front().se; q.pop();
        if(!state){
            cout << step << nl;
            return 0;
        }
        for(int i=0; i<n; i++){
            if(state & (1<<i)) continue;
            int next = nstate(state | (1<<i));
            if(!vis[next]){
                vis[next] = 1;
                q.push({step+1, next});
            }
        }
    }
}
