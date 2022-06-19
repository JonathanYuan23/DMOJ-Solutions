#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
#define INF 0x3f3f3f3f
using namespace std;
typedef pair<int, int> pii;
const int MAXN=1005;

unordered_map<int, vector<int>> xy;
map<pii, set<int>> yx;

int main() {

    ios_base::sync_with_stdio(0); cin.tie(NULL);  cout.tie(NULL);

    int n, x, y;
    cin >> n;

    for(int i=0; i<n; i++){
        cin >> x >> y;
        xy[x].push_back(y);
    }

    for(auto n: xy){
        if(n.second.size()<=1) continue;
        for(int i=0; i<n.second.size()-1; i++){
            for(int j=i+1; j<n.second.size(); j++){
                x=n.second[i];  y=n.second[j];
                if(x>y) swap(x, y);
                yx[{x, y}].insert(n.first);
            }
        }
    }

    int maxx=INT_MIN;
    for(auto n: yx){
        if(n.second.size()<=1) continue;
        int y1=n.first.first, y2=n.first.second, x1=*n.second.begin(), x2=*n.second.rbegin();
        maxx=max(maxx, abs(y2-y1)*abs(x2-x1));
    }

    cout << ((maxx==INT_MIN)?0:maxx) << "\n";

    return 0;
}
