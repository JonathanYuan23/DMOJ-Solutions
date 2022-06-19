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
#define MAX 50005
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

int n, id = 0, vis[MAX * 2];
string arr1[MAX], arr2[MAX];
unordered_map<int, string> pairing;
unordered_map<string, int> ids;
vi graph[MAX * 2];

bool is_number(string s){
    for(auto &c: s) if(!isdigit(c)) return 0;
    return 1;
}

bool dfs(int node, string &same){
    vis[node] = 1;
    bool ans = 0;
    if(same == "-1" && pairing.count(node)) same = pairing[node];
    else if(same != "-1" && pairing.count(node)) if(pairing[node] != same) return 1;
    for(auto to: graph[node]) if(!vis[to]) ans |= dfs(to, same);
    return ans;
}

bool solve(){
    for(int i=0; i<n; i++){
        if(is_number(arr1[i]) && !is_number(arr2[i])){
            if(!pairing.count(ids[arr2[i]])) pairing[ids[arr2[i]]] = arr1[i];
            else if(pairing[ids[arr2[i]]] != arr1[i]) return 0;
        }
        else if(!is_number(arr1[i]) && is_number(arr2[i])){
            if(!pairing.count(ids[arr1[i]])) pairing[ids[arr1[i]]] = arr2[i];
            else if(pairing[ids[arr1[i]]] != arr2[i]) return 0;            
        }
        else if(!is_number(arr1[i]) && !is_number(arr2[i])){
            graph[ids[arr1[i]]].pb(ids[arr2[i]]);
            graph[ids[arr2[i]]].pb(ids[arr1[i]]);
        }
        else if(is_number(arr1[i]) && is_number(arr2[i]) && arr1[i] != arr2[i]) return 0;
    }
    for(int i=0; i<id; i++){
        if(!vis[i] && !graph[i].empty()){
            string same = "-1";
            if(dfs(i, same)) return 0;
        }
    }
    return 1;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);  cout.tie(NULL);
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> arr1[i];
        if(!is_number(arr1[i])){
            if(!ids.count(arr1[i])){
                ids[arr1[i]] = id;
                id++;
            }
        }
    }
    for(int i=0; i<n; i++){
        cin >> arr2[i];
        if(!is_number(arr2[i])){
            if(!ids.count(arr2[i])){
                ids[arr2[i]] = id;
                id++;
            }
        }
    }
    cout << ((solve()) ? "DA" : "NE") << nl;
    
    return 0;
};
