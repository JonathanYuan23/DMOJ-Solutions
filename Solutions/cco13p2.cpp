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
#define MAX 1050005
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

struct Node{
    int idx, score;
} st[4 * MAX];

int n, m, arr[MAX];
char query;

void push(int i){
    if(st[i*2].score > st[i*2+1].score){
        st[i].score = st[i*2].score;
        st[i].idx = st[i*2].idx;
    }
    else{
        st[i].score = st[i*2+1].score;
        st[i].idx = st[i*2+1].idx;
    }
}

void build(int i, int l, int r){
    if(l==r){
        st[i].score = arr[l];
        st[i].idx = l;
        return;
    }
    int mid = (l + r) / 2;
    build(i*2, l, mid);
    build(i*2+1, mid+1, r);
    push(i);
}

void update(int i, int l, int r, int pos, int val){
    if(l==r){
        st[i].score = val;
        return;
    }
    int mid = (l + r) / 2;
    if(pos<=mid) update(i*2, l, mid, pos, val);
    else update(i*2+1, mid+1, r, pos, val);
    push(i);
}

int print(int i, int l, int r, int pos, int won){
    if(l==r) return won;
    if(st[i].idx == pos) won++;
    int mid = (l + r) / 2;
    if(pos<=mid) return print(i*2, l, mid, pos, won);
    else return print(i*2+1, mid+1, r, pos, won);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);  cout.tie(NULL);
    cin >> n >> m;
    n = pow(2, n);
    for(int i=1; i<=n; i++) cin >> arr[i];
    build(1, 1, n);
    for(int i=1, pos, s; i<=m; i++){
        cin >> query;
        if(query == 'R'){
            cin >> pos >> s;
            update(1, 1, n, pos, s);
        }
        else if(query == 'W'){
            cout << st[1].idx << nl;
        }
        else{
            cin >> pos;
            cout << print(1, 1, n, pos, 0) << nl;
        }
    }
    
    return 0;
};
