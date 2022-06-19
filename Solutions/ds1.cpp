#pragma GCC optimize "Ofast"
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MOD 1000000009
#define p 31
#define INF 0x3f3f3f3f
#define MAXN 1000005
#define pb push_back
#define LSB(S) (S & (-S))
typedef vector<int> vi;
typedef vector<vector<int>> vii;

class FenwickTree {
private:
  ll ft[MAXN], ft2[MAXN];
public:
  FenwickTree(int n) {}
  ll rsq(int b) { ll sum = 0; for (; b; b -= LSB(b)) sum += ft[b]; return sum; }
  ll rsq2(int b) { ll sum = 0; for (; b; b -= LSB(b)) sum += ft2[b]; return sum; }
  ll rsq(int a, int b) { return rsq(b) - (a == 1 ? 0 : rsq(a - 1)); }
  void update(int k, int v, int n) { if(n==0) for (; k < MAXN; k += LSB(k)) ft[k] += v; else for (; k < MAXN; k += LSB(k)) ft2[k] += v;}
  void range(int l, int r, int val){ update(l, val, 0); update(r+1, -val, 0); }
};

int N, M, X, V, arr[MAXN];
char c;

int main() {

    ios_base::sync_with_stdio(0); cin.tie(NULL);  cout.tie(NULL);

    cin >> N >> M;
    FenwickTree ft(N);
    for(int i=1; i<=N; i++){cin >> arr[i]; ft.update(i, arr[i], 0); ft.update(arr[i], 1, 1);}
    for(int i=0; i<M; i++){
        cin >> c;
        if(c=='C') {
            cin >> X >> V;
            ft.update(X, V-arr[X], 0);
            ft.update(arr[X], -1, 1);
            arr[X]=V;
            ft.update(arr[X], 1, 1);
        } else if(c=='S') {
            cin >> X >> V;
            cout << ft.rsq(X, V) << "\n";
        } else {
            cin >> V;
            cout << ft.rsq2(V) << "\n";
        }
    }

    return 0;
}
