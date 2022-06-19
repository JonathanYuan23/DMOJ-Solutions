#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize "Ofast"
#define ll long long
#define ull unsigned long long
#define MOD 1e9+7
#define fi first
#define se second
#define INF 0x3f3f3f3f
#define MAXN 30005
#define pb push_back
#define LSB(S) (S & (-S))
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<piii> viii;

int streets[1005][MAXN];
int rows, cols, shops;

int newy(int x, int y, int r, int nx){
    ll xh, yk, ny, a, b, c;
    xh = (x>0) ? -2*x : 2*x;
    yk = (y>0) ? -2*y : 2*y;
    a = 1;
    b = yk; 
    c = (x*x) + (y*y) - (r*r);
    c += (nx*nx) + (xh*nx);
    double temp = (-b + sqrt((b*b)-(4*a*c)))/(2*a);
    return ny = temp;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);  cout.tie(NULL);
    cin >> rows >> cols >> shops;
    int x, y, r, b, s, e;
    for(int i=0; i<shops; i++){
        cin >> x >> y >> r >> b;
        s = max(1, x-r), e = min(1000, x+r);
        for(int j=s; j<=e; j++){
            int sy, ey, dis = newy(x, y, r, j);
            sy = max(1, y-(dis-y));
            ey = min(MAXN-5, dis);
            streets[j][sy] += b;
            streets[j][ey+1] -= b;
        }
    }
    int mx = INT_MIN, count = 0; 
    for(int i=1; i<=cols; i++){
        int bitrate = 0;
        for(int j=1; j<=rows; j++){
            bitrate += streets[i][j];
            if(bitrate>mx){
                mx = bitrate;
                count = 1;
            }
            if(bitrate==mx) count++;
        }
    }
    cout << mx << "\n" << count-1 << "\n";

    return 0;
}
