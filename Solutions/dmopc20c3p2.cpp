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
#define MAX 200005
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

int singers, beats, k, arr[MAX][25];
vii cols[25];
set<pii> difs[25];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL);  cout.tie(NULL);
    cin >> singers >> beats >> k;
    for(int i=0; i<singers; i++){
        for(int j=0; j<beats; j++){
            cin >> arr[i][j];
            cols[j].pb({arr[i][j], i});
        }
    }
    for(int i=0; i<beats; i++){
        sort(cols[i].begin(), cols[i].end());
        // get difs
        int high = 0, lo = 0;
        while(high != sz(cols[i]) - 1 || lo != sz(cols[i]) - 1){
            int dif = cols[i][high].fi - cols[i][lo].fi;
            if(dif == k){
                difs[i].insert({cols[i][high].se, cols[i][lo].se});
                if(high < sz(cols[i]) - 1) high++;
                else lo++;
            }
            else if(dif > k){
                if(lo < high) lo++;
                else high++;                
            }  
            else{
                if(high < sz(cols[i]) - 1) high++;
                else lo++;                
            }
        }
    }
    int ans = 0;
    for(int i=0; i<beats-1; i++){
        for(auto beat: difs[i]){
            if(difs[i+1].find(beat) != difs[i+1].end()) ans++;
        }
    }
    cout << ans << '\n';

    return 0;
};
