//#pragma GCC optimize "Ofast"
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MOD 1000000009
#define p 31
#define INF 0x3f3f3f3f
#define MAXN 105
#define pb push_back
#define LSB(S) (S & (-S))
#define um unordered_map
typedef vector<string> vs;
typedef vector<int> vi;

um<string, int> id;  um<int, string> rev;  vi graph[MAXN];   bool vis[MAXN]; int pre[MAXN];
int m, n, u, v, ind=0;
string su, sv;

void bfs(){
    queue<int> q;
    q.push(id[su]);
    vis[id[su]]=1;
    v=id[sv];
    while(!q.empty()){
        u=q.front(); q.pop();
        if(u==v){
            string res="";
            res+=rev[v][0];
            while(pre[v]!=-1){
                res+=rev[pre[v]][0];
                v=pre[v];
            }
            reverse(res.begin(), res.end());
            cout << res << "\n";
            return;
        }
        for(auto x: graph[u]){
            if(!vis[x]){
                q.push(x);
                vis[x]=1;
                pre[x]=u;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL);  cout.tie(NULL);
    cin >> m >> n;
    for(int i=0; i<m; i++){
        cin >> su >> sv;
        if(id.find(su)==id.end()){id[su]=ind; rev[ind]=su; ind++;}
        if(id.find(sv)==id.end()){id[sv]=ind; rev[ind]=sv; ind++;}
        graph[id[su]].push_back(id[sv]);
        graph[id[sv]].push_back(id[su]);
    }
    for(int i=0; i<n; i++){
        memset(vis, 0, sizeof vis);
        memset(pre, -1, sizeof pre);
        cin >> su >> sv;
        bfs();
    }

    return 0;
}
