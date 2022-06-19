#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize "Ofast"
#define ll long long
#define ull unsigned long long
#define MOD 1e9+7
#define fi first
#define se second
#define INF 0x3f3f3f3f
#define MAX 500005
#define pb push_back
#define LSB(S) (S & (-S))
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<piii> viii;

int n, h, s, heights[MAX];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);  cout.tie(NULL);
    cin >> n >> h;
    for(int i=0; i<n; i++){
        cin >> s;
        if(i%2==0){
            heights[1]++;
            heights[1+s]--;
        }
        else{
            heights[h-s+1]++;
            heights[h+1]--;
        }
    }
    int sum = 0, mn = INT_MAX, nm = 0;
    for(int i=1; i<=h; i++){
        sum += heights[i];
        if(sum == mn) nm++;
        else if(sum < mn){
            mn = sum;
            nm = 1;
        }
    }
    cout << mn << " " << nm << "\n";
    return 0;
}
