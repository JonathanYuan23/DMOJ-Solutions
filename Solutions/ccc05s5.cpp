#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 1e5+2;
int N, rk, a[MM], bit[MM]; map<int, int> mp; ll ans;
void update(int idx, int val){
    for(int i=idx; i<MM; i+=i&-i) bit[i]+=val;
}
int query(int idx){
    int sum = 0;
    for(int i=idx; i>0; i-=i&-i) sum += bit[i];
    return sum;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for(int i=1; i<=N; i++){
        cin >> a[i];  mp[a[i]] = 0;
    }
    for(auto &x : mp) x.second = ++rk;
    for(int i=1; i<=N; i++) {
        int x = mp[a[i]];
        ans += i - query(x);
        update(x, 1);
    }
    cout << fixed << setprecision(2) << (double)ans/N << endl;
}
