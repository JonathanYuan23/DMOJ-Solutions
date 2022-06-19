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

int N, M, L, start, farthest, maxd, center, rad, dis[MAX], pre[MAX], vis[MAX], A[MAX], B[MAX], T[MAX];
vector<pii> graph[MAX], centers;

void dfs(int cur, int par, int mx){
    dis[cur]=mx;
    vis[cur]=1;
    if(mx>maxd){
        maxd=mx;
        farthest=cur;
    }
    for(auto x: graph[cur]){
        if(x.fi!=par){
            pre[x.fi]=cur;
            dfs(x.fi, cur, mx+x.se);
        }
    }
}

void findCenter(int node, int limit){
    maxd=INT_MIN;
    dfs(node, -1, 0);
    maxd=INT_MIN; start=farthest;
    dfs(farthest, -1, 0);
    if(limit==1) return;
    rad=INT_MAX; center=node;
    for(; farthest!=start; farthest=pre[farthest]){
        if(max(maxd-dis[farthest], dis[farthest])<rad){
            center=farthest; 
            rad=max(maxd-dis[farthest], dis[farthest]);
        }
    }
    if(rad==INT_MAX) rad=0;
    centers.pb({rad, center});
}

int travelTime(int N, int M, int L, int A[], int B[], int T[]){
    for(int i=0; i<M; i++){
        graph[A[i]].pb({B[i], T[i]});
        graph[B[i]].pb({A[i], T[i]});
    }
    memset(vis, 0, sizeof vis);
    for(int i=0; i<N; i++) if(!vis[i]) findCenter(i, 0);
    sort(centers.rbegin(), centers.rend());
    int connect=centers[0].se;
    for(int i=1; i<centers.size(); i++){
        graph[connect].pb({centers[i].se, L});
        graph[centers[i].se].pb({connect, L});
    }
    findCenter(0, 1);
    return maxd;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL);  cout.tie(NULL);
    cin >> N >> M >> L;
    for(int i=0; i<M; i++) cin >> A[i] >> B[i] >> T[i];
    cout << travelTime(N, M, L, A, B, T) << "\n";

    return 0;
}
