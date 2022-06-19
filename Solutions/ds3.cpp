#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize "Ofast"
#define ll long long
#define ull unsigned long long
#define MOD 1e9+7
#define fi first
#define se second
#define INF 0x3f3f3f3f
#define MAX 100005
#define pb push_back
#define LSB(S) (S & (-S))
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<piii> viii;

struct node{
    int value, gcd, occurrences;
};

int N, M, arr[MAX];
node st[MAX*4];

void push(int i){
    st[i].value = min(st[i*2].value, st[i*2+1].value);
    st[i].gcd = __gcd(st[i*2].gcd, st[i*2+1].gcd);
    st[i].occurrences = 0;
    if(st[i].gcd==st[i*2].gcd) st[i].occurrences += st[i*2].occurrences;
    if(st[i].gcd==st[i*2+1].gcd) st[i].occurrences += st[i*2+1].occurrences;
}

void build(int i, int l, int r){
    if(l==r){
        st[i].value = arr[l];
        st[i].gcd = arr[l];
        st[i].occurrences = 1;
        return;
    }
    int mid = (l + r) / 2;
    build(i*2, l, mid);
    build(i*2+1, mid+1, r);
    push(i);
}

void update(int i, int l, int r, int pos, int val){
    if(l==r){
        st[i].value = val;
        st[i].gcd = val;
        return;
    }
    int mid = (l + r) / 2;
    if(pos<=mid) update(i*2, l, mid, pos, val);
    else update(i*2+1, mid+1, r, pos, val);
    push(i);
}

// ql and qr are the current query, l and r are the current bounds of the node
int rmq(int i, int ql, int qr, int l, int r){
    if(l>=ql && r<=qr) return st[i].value;
    int mid = (l + r) / 2;
    if(qr<=mid) return rmq(i*2, ql, qr, l, mid);
    if(ql>mid) return rmq(i*2+1, ql, qr, mid+1, r);
    return min(rmq(i*2, ql, qr, l, mid), rmq(i*2+1, ql, qr, mid+1, r));
}

int rgcdq(int i, int ql, int qr, int l, int r){
    if(l>=ql && r<=qr) return st[i].gcd;
    int mid = (l + r) / 2;
    if(qr<=mid) return rgcdq(i*2, ql, qr, l, mid);
    if(ql>mid) return rgcdq(i*2+1, ql, qr, mid+1, r);
    return __gcd(rgcdq(i*2, ql, qr, l, mid), rgcdq(i*2+1, ql, qr, mid+1, r));
}

int roq(int i, int ql, int qr, int l, int r, int cgcd){
    if(l>=ql && r<=qr) return (st[i].gcd==cgcd) ? st[i].occurrences : 0;
    int mid = (l + r) / 2;
    if(qr<=mid) return roq(i*2, ql, qr, l, mid, cgcd);
    if(ql>mid) return roq(i*2+1, ql, qr, mid+1, r, cgcd);
    return roq(i*2, ql, qr, l, mid, cgcd) + roq(i*2+1, ql, qr, mid+1, r, cgcd);
}

void print(int i, int l, int r){
    if(l==r){
        cout << st[i].value << " ";
        return;
    }
    int mid = (l+r)/2;
    print(i*2, l, mid);
    print(i*2+1, mid+1, r);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL);  cout.tie(NULL);
    cin >> N >> M;
    for(int i=1; i<=N; i++) cin >> arr[i];
    build(1, 1, N);
    char c;
    int l, r;
    for(int i=0; i<M; i++){
        cin >> c >> l >> r;
        if(c=='C') update(1, 1, N, l, r);
        if(c=='M') cout << rmq(1, l, r, 1, N) << '\n';
        if(c=='G') cout << rgcdq(1, l, r, 1, N) << '\n';
        if(c=='Q') cout << roq(1, l, r, 1, N, rgcdq(1, l, r, 1, N)) << '\n';
    }

    return 0;
}
