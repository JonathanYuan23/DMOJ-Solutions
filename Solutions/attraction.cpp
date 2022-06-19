#pragma GCC optimize "Ofast"
#include <bits/stdc++.h>
using namespace std; using pii = pair<int, int>;  using piii = pair<int, pii>;  using piiii = pair<pii, pii>;  using vi = vector<int>;  using vii = vector<pii>;  using viii = vector<piii>;  using viiii = vector<piiii>;
#define frein freopen("input.txt", "r", stdin)
#define freout freopen("output.txt", "w", stdout)
#define ll long long
#define ull unsigned long long
#define fi first
#define pb push_back
#define pf push_front
#define ppb pop_back
#define LSB(x) (x & (-x))
#define sz(x) (int)(x.size())

const int MOD = 1000000007, INF = 0x3f3f3f3f, MX = 1005, IMX = INT_MAX, IMN = INT_MIN;
const long long LLMX = LONG_LONG_MAX, LLMN = LONG_LONG_MIN;
const char nl = '\n';

int T, N, A, B;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL);  cout.tie(NULL);
    cin >> T;
    while(T--){
        cin >> N >> A >> B;
        vi p(A);
        for(int i=0; i<A; i++) cin >> p[i];
        sort(p.begin(), p.end());
        priority_queue<pii> q;
        if(p[0] > 1) q.push({p[0] - 1, 0});
        if(p.back() < N) q.push({N - p.back(), 0});
        for(int i=1; i<A; i++){
            int gap = p[i] - p[i-1] - 1;
            if(gap <= 0) continue;
            if(gap % 2 == 0) q.push({gap / 2, 2});
            else q.push({(gap + 1) / 2, 3});
        }
        int ans = 0, val, state;
        while(!q.empty() && B){
            tie(val, state) = q.top();
            q.pop(); B--;
            ans += val;
            if(state == 2) q.push({val, 0});
            if(state == 3 && val >= 2) q.push({val - 2, 1});
            if(state == 1) q.push({1, 0});
        }
        cout << ans << nl;
    }
    
    return 0;
}
