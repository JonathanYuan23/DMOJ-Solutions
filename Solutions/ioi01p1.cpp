#pragma GCC optimize "Ofast"
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MOD 1000000009
#define p 31
#define INF 0x3f3f3f3f
#define MAXN 1030
#define pb push_back
#define LSB(S) (S & (-S))
typedef vector<int> vi;
typedef vector<vector<int>> vii;

class FenwickTree{
private:
    vii ft;

public:

    int query(int x, int y){
        int sum = 0;
        for(int x_ = x; x_ > 0; x_ = x_ - LSB(x_)){
            for(int y_ = y; y_ > 0; y_ = y_ - LSB(y_)){
                sum = sum + ft[x_][y_];
            }
        }
        return sum;
    }

    int query(int x1, int y1, int x2, int y2){
        return (query(x2, y2) - query(x2, y1-1) - query(x1-1, y2) + query(x1 - 1, y1 - 1));
    }

    void update(int x, int y, int value){
        for(int x_ = x; x_ < ft.size(); x_ = x_ + LSB(x_)){
            for(int y_ = y; y_ < ft[0].size(); y_ = y_ + LSB(y_)){
                ft[x_][y_] += value;
            }
        }
    }

    FenwickTree(int s){
        int n = s, m = s;
        ft.assign(n + 1, vector<int> (m + 1, 0));
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j)
                update(i + 1, j + 1, 0);
        }
    }
};

int main() {

    ios_base::sync_with_stdio(0); cin.tie(NULL);  cout.tie(NULL);

    FenwickTree ft(MAXN);
    int query, s, x, y, v, l, b, r, t;
    cin >> query;
    while(query!=3){
        if(query==0){
            cin >> s;
        } else if(query==1){
            cin >> x >> y >> v;
            swap(x, y);
            ft.update(s-x, y+1, v);
        } else if(query==2){
            cin >> l >> b >> r >> t;
            swap(l, t); swap(r, b);
            cout << ft.query(s-l, t+1, s-r, b+1) << '\n';
        }
        cin >> query;
    }

    return 0;
}
