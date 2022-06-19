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
#define INF 0x3f3f3f3f3f3f3f3f
#define MAX 105
#define pb push_back
#define LSB(S) (S & (-S))
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<pii, pii> piiii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<piii> viii;
typedef vector<piiii> viiii;

int M, Q, dp[MAX], keep[MAX], times[MAX], st[4*MAX];
vector<vector<string>> res;
string q[MAX];

void build(int i, int l, int r){
    if(l==r){
        st[i] = times[l];
        return;
    }
    int mid = (l + r) / 2;
    build(i*2, l, mid);
    build(i*2+1, mid+1, r);
    st[i] = max(st[i*2], st[i*2+1]);
}

int rmq(int i, int ql, int qr, int l, int r){
    if(l>=ql && r<=qr) return st[i];
    int mid = (l + r) / 2;
    if(qr<=mid) return rmq(i*2, ql, qr, l, mid);
    if(ql>mid) return rmq(i*2+1, ql, qr, mid+1, r);
    return max(rmq(i*2, ql, qr, l, mid), rmq(i*2+1, ql, qr, mid+1, r));
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL);  cout.tie(NULL);
    cin >> M >> Q;
    for(int i=1; i<=Q; i++) cin >> q[i] >> times[i];
    build(1, 1, Q);
    for(int i=1; i<=Q; i++){
        dp[i] = INT_MAX;
        for(int j=1; j<=M; j++){
            if(i-j >= 0){
                int newCost = rmq(1, i-j+1, i, 1, Q) + dp[i-j];
                if(newCost < dp[i]){
                    dp[i] = newCost;
                    keep[i] = j;
                }
            }
        }
    }
    cout << "Total Time: " << dp[Q] << '\n';
    int current = Q;
    while(current!=0){
        vector<string> temp;
        for(int i=current-keep[current]+1; i<=current; i++) temp.pb(q[i]);
        res.pb(temp);
        current = current - keep[current];
    }
    for(int i=res.size()-1; i>=0; i--){
        for(int j=0; j<res[i].size(); j++) cout << res[i][j] << ' ';
        cout << '\n';
    }

    return 0;
}
