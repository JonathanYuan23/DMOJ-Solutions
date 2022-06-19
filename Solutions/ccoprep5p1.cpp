#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize "Ofast"
#define frein freopen("input.txt", "r", stdin)
#define freout freopen("output.txt", "w", stdout)
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define nl '\n'
#define fi first
#define se second
#define INF 0x3f3f3f3f
#define MAX 1005
#define IMX INT_MAX
#define IMN INT_MIN
#define LLMX LONG_LONG_MAX
#define LLMN LONG_LONG_MIN
#define pb push_back
#define pf push_front
#define LSB(x) (x & (-x))
#define sz(x) (ll)(x.size())
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<pii, pii> piiii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<piii> viii;
typedef vector<piiii> viiii;  

int ans, k, n, m, grid[MAX][MAX], histogram[MAX], lf[MAX], rt[MAX];

void solve(){
    stack<int> order;
    for(int i=0; i<m; i++){
        if(order.empty()){
            lf[i] = 0;
            order.push(i);
        }
        else{
            while(!order.empty() && histogram[order.top()] >= histogram[i]) order.pop();
            lf[i] = ((order.empty()) ? 0 : order.top() + 1);
            order.push(i);
        }
    }
    while(!order.empty()) order.pop();
    for(int i=m-1; i>=0; i--){
        if(order.empty()){
            rt[i] = m-1;
            order.push(i);
        }
        else{
            while(!order.empty() && histogram[order.top()] >= histogram[i]) order.pop();
            rt[i] = ((order.empty()) ? m-1 : order.top() - 1);
            order.push(i);
        }
    }    
    for(int i=0; i<m; i++) ans = max(ans, histogram[i] * (rt[i] - lf[i] + 1));
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL);  cout.tie(NULL);
    cin >> k;
    for(int tc=0; tc<k; tc++){
        cin >> n >> m;
        char cell;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin >> cell;
                grid[i][j] = ((cell == 'R') ? 0 : 1);
            }
        }
        ans = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!grid[i][j]) histogram[j] = 0;
                else histogram[j]++;
            }
            solve();
        }
        cout << ans * 3 << nl;
        memset(histogram, 0, sizeof histogram);
    }

    return 0;
}
