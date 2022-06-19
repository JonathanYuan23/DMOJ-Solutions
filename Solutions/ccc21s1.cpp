#include <bits/stdc++.h>
using namespace std;

#define frein freopen("input.txt", "r", stdin)
#define MAX 10010

double n, heights[MAX], widths[MAX];
double ans = 0.0;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL);  cout.tie(NULL);
    cin >> n;
    for(int i=0; i<=n; i++) cin >> heights[i];
    for(int i=0; i<n; i++) cin >> widths[i];
    for(int i=0; i<n; i++){
        double l = heights[i], r = heights[i + 1], w = widths[i];
        if(r < l) swap(l, r);
        int dif = r - l;
        ans += w * l;
        ans += ((double)(dif) * (double)(w)) / 2;
    }
    cout << fixed << setprecision(1) << ans << '\n';
    
    return 0;
}
