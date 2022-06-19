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
#define MAX 100005
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

int N, P, ans = 0, counter = 1;
vii planets;

bool comp(const pii &a, const pii &b){
    int valueA = a.fi - a.se, valueB = b.fi - b.se;
    if(valueA >= 0 && valueB >= 0) return a.se < b.se;
    if(valueA >= 0) return 1;
    if(valueB >= 0) return 0;
    return valueA > valueB;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL);  cout.tie(NULL);
    cin >> N >> P;
    for(int i=1, a, b; i<=N; i++){
        cin >> a >> b;
        if(i == P){
            ans += a;
            continue;
        }
        planets.pb({a, b});
    }
    sort(planets.begin(), planets.end(), comp);
    for(auto planet: planets){
        int value = planet.fi - planet.se;
        if(value < 0 || ans < planet.se) break;
        ans += value;
        counter++;
    }
    cout << ans << '\n' << counter << '\n';
    
    return 0;
};
