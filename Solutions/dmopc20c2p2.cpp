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

map<int, pii> pos;
int sca[MAX];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);  cout.tie(NULL);
    // freopen("input.txt", "r", stdin);
    int n, m, a, b;
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        cin >> sca[i];
        if(pos.find(sca[i])==pos.end()){
            pos[sca[i]].fi = i;
            pos[sca[i]].se = i;
        }
        else{
            pos[sca[i]].fi = min(pos[sca[i]].fi, i);
            pos[sca[i]].se = max(pos[sca[i]].se, i);
        }
    }
    int ans = 0;
    for(int i=0; i<m; i++){
        cin >> a >> b;
        if(pos.find(a)==pos.end() || pos.find(b)==pos.end()) continue;
        else{
            if(pos[a].fi<=pos[b].fi) ans = max(ans, pos[b].fi-pos[a].fi+1);
            if(pos[a].fi<=pos[b].se) ans = max(ans, pos[b].se-pos[a].fi+1);
            if(pos[a].se<=pos[b].fi) ans = max(ans, pos[b].fi-pos[a].se+1);
            if(pos[a].se<=pos[b].se) ans = max(ans, pos[b].se-pos[a].se+1);
        }
    }
    cout << ans << '\n';

    return 0;
}
