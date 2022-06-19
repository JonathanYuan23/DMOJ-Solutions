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
#define MAX 1005
#define IMX INT_MAX
#define IMN INT_MIN
#define LLMX LONG_LONG_MAX
#define LLMN LONG_LONG_MIN
#define pb push_back
#define pf push_front
#define LSB(x) (x & (-x))
#define sz(x) (int)(x.size())
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<pii, pii> piiii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<piii> viii;
typedef vector<piiii> viiii;

int va, vb, m, dis[MAX][MAX];

string ids[] = {"0", "pour A B", "pour B A", "fill A", "fill B", "chug A", "chug B"};

// pair first is op, pair second is amount
pii pre[MAX][MAX], endAmounts = {-1, -1};

vi ops;

//------------- pours -------------
// pour A - B, 1 <= pour <= content_A (1)
// pour B - A 1 <= pour <= content_B (2)
//------------- fill -------------
// fill A (3)
// fill B (4)
//------------- chug -------------
// chug A (5)
// chug B (6)

void bfs(){
    memset(dis, -1, sizeof dis);
    for(int i=0; i<=va; i++) for(int j=0; j<=vb; j++) pre[i][j] = {-1, -1};
    queue<pii> q;
    // A B
    q.push({0, 0});
    dis[0][0] = 0;
    while(!q.empty()){
        int A = q.front().fi, B = q.front().se;
        q.pop();
        if(A == m || B == m){
            endAmounts = {A, B};
            return;
        }
        if(A > 0){
            int transfer = min(A, vb-B);
            if(dis[A-transfer][B+transfer] == -1 && B != vb){
                dis[A-transfer][B+transfer] = dis[A][B] + 1;
                pre[A-transfer][B+transfer] = {1, transfer};
                q.push({A-transfer, B+transfer});
            }
            if(dis[0][B] == -1){
                dis[0][B] = dis[A][B] + 1;
                pre[0][B] = {5, A};
                q.push({0, B});                
            }
        }
        if(B > 0){
            int transfer = min(B, va-A);
            if(dis[A+transfer][B-transfer] == -1 && A != va){
                dis[A+transfer][B-transfer] = dis[A][B] + 1;
                pre[A+transfer][B-transfer] = {2, transfer};
                q.push({A+transfer, B-transfer});
            }
            if(dis[A][0] == -1){
                dis[A][0] = dis[A][B] + 1;
                pre[A][0] = {6, B};
                q.push({A, 0});                
            }
        }
        if(A < va){
            if(dis[va][B] == -1){
                dis[va][B] = dis[A][B] + 1;
                pre[va][B] = {3, va-A};
                q.push({va, B});
            }
        }
        if(B < vb){
            if(dis[A][vb] == -1){
                dis[A][vb] = dis[A][B] + 1;
                pre[A][vb] = {4, vb-B};
                q.push({A, vb});
            }
        }
    }
}

void adjust(int &A, int &B, int op, int amount){
    switch(op){
        case 1: 
            A += amount;
            B -= amount;
            break;
        case 2:
            B += amount;
            A -= amount;
            break;
        case 3:
            A -= amount;
            break;
        case 4:
            B -= amount;
            break;
        case 5:
            A += amount;
            break;
        case 6:
            B += amount;
            break;
    }
}

void solve(){
    cin >> va >> vb >> m;
    if(va < m && vb < m){
        cout << "Not possible\n";
        return;
    }
    if(va == m){
        cout << "fill A\n";
        return;
    }
    if(vb == m){
        cout << "fill B\n";
        return;
    }                     
    bfs();
    if(endAmounts.fi == -1){
        cout << "Not possible\n";
        return;
    }
    int A = endAmounts.fi, B = endAmounts.se;
    while(!(A == 0 && B == 0)){
        ops.pb(pre[A][B].fi);
        adjust(A, B, ops.back(), pre[A][B].se);
    }
    reverse(ops.begin(), ops.end());
    for(auto op: ops) cout << ids[op] << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL);  cout.tie(NULL);
    solve();
    
    return 0;
};
