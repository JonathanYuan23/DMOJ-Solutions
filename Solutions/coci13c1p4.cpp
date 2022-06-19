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
#define INF 0x3f3f3f3f3f3f3f3f
#define MAX 1005
#define pb push_back
#define LSB(S) (S & (-S))
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<pii, pii> piiii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<piii> viii;
typedef vector<piiii> viiii;

/*
    given two jewels: 5, 99; 2, 23;
    and the bags: 2, 6

    if bag two were to hold jewel two, then the first jewel wouldn't be taken because the first bag is too small
    however if bag one were to hold jewel two, then the first jewel could be held in bag two

    let's say now that the jewels are: 5, 99; 2, 23; 2, 100;
    and the bags remain the same

    in this case, because there are two jewels of weight 2, but the third has a greater value, put the third jewel in the first bag

    therefore we can say that a greedy solution is to sort by weight, breaking ties with value
    
    but if the jewels were: 2, 23; 5, 99;
    and there's just one bag: 5
    
    this would not work, so an alternate solution is to sort by decreasing order of value, and breaking ties with weight
    
    use a multiset to store the bags and guarantee a log2N lowerbound complexity
*/

bool comp(const pii &a, const pii &b){
    if(a.se == b.se) return a.fi < b.fi;
    return a.se > b.se;
}

int N, K;
multiset<int> bags;
vii jewels;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL);  cout.tie(NULL);
    cin >> N >> K;
    jewels.resize(N);
    for(int i=0; i<N; i++) cin >> jewels[i].fi >> jewels[i].se;
    for(int i=0, b; i<K; i++){
        cin >> b;
        bags.insert(b);
    }
    sort(jewels.begin(), jewels.end(), comp);
    ull ans = 0;
    for(int i=0; i<N; i++){
        int currWeight = jewels[i].fi, currValue = jewels[i].se;
        auto pos = bags.lower_bound(currWeight);
        if(bags.size()>0 && pos!=bags.end()){
            ans += currValue;
            bags.erase(pos);
        }
    }
    cout << ans << '\n';

    return 0;
}
