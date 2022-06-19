#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize "Ofast"
#define ll long long
#define ull unsigned long long
#define MOD 1e9+7
#define fi first
#define se second
#define INF 0x3f3f3f3f
#define MAX 1005
#define pb push_back
#define LSB(S) (S & (-S))
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<piii> viii;

vi graph[MAX];

void dfs(int node, int pre, int &sum, int &mx, int longest){
    mx = max(mx, longest);
    for(auto to: graph[node]){
        if(to==pre) continue;
        sum += 2;
        dfs(to, node, sum, mx, longest+1);
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);  cout.tie(NULL);
    for(int tc=0; tc<5; tc++){
        string temp, tree = ""; 
        getline(cin, temp);
        for(int i=0; i<temp.size(); i++){
            if(temp[i]!=' ') tree += temp[i];
            if(i>0 && isdigit(temp[i]) && isdigit(temp[i-1])) tree+='*';
        }
        if(tree.size()==3 || tree.size()==1){
            cout << 0 << " " << ((tree.size()==3) ? (tree[0]-'0')*10 + tree[1]-'0' : tree[0]-'0') << "\n";
            continue;
        }
        int node = 0, sum = 0, i = 0;
        stack<int> edges;
        while(i<tree.size()){
            if(edges.empty()){
                edges.push(node);
                i++;
                continue;
            }
            if(tree[i]=='*'){
                i++;
                continue;
            }
            if(tree[i]=='('){
                node++;
                graph[edges.top()].pb(node);
                edges.push(node);
                i++;
            }
            else if(tree[i]==')'){
                edges.pop();
                i++;
            }
            else{
                node++;
                graph[edges.top()].pb(node);
                if(i<=tree.length()-3 && isdigit(tree[i+1]) && tree[i+2]=='*'){
                    sum += (tree[i]-'0')*10 + tree[i+1]-'0';
                    i += 3;
                }
                else{
                    sum += tree[i]-'0';
                    i++;
                }
            }
        }
        int tot = 0, mx = -1;
        dfs(0, -1, tot, mx, 0);
        cout << tot-mx << " " << sum << '\n';
        for(int i=0; i<=node; i++) graph[i].clear();
    }
    return 0;
}
