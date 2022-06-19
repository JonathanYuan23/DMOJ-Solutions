#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize "Ofast"
#define ll long long
#define MOD 1000000007
#define fi first
#define se second
#define INF 0x3f3f3f3f
#define MAXN 105
#define pb push_back
#define LSB(S) (S & (-S))
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<pii, pii> piiii;
typedef pair<int, piiii> piiiii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<piii> viii;

int disr[8] = {1, 2, 2, 1, -1, -2, -2, -1}, disc[8] = {-2, -1, 1, 2, 2, 1, -1, -2};

int dis[MAXN][MAXN][MAXN], n, r, c, pr, pc, kr, kc;

bool valid(int row, int col, int pawnr, int pawnc){
    return row>=1 && row<=r && col>=1 && col<=c && dis[row][col][pawnr]==-1;
}

void bfs(){
    int beat=INT_MAX, stale=INT_MAX, loss=INT_MAX;
    dis[kr][kc][pr]=0;
    queue<piiiii> q;
    q.push({0, {{pr, pc}, {kr, kc}}});
    while(!q.empty()){
        int rp=q.front().second.first.first, cp=q.front().second.first.second, rk=q.front().second.second.first, ck=q.front().second.second.second, move=q.front().first;
        q.pop();
        if(rp==r){
            loss = min(loss, dis[rk][ck][rp]);
            continue;
        }
        if(!move){
            dis[rk][ck][rp+1] = dis[rk][ck][rp];
            q.push({1, {{rp+1, cp}, {rk, ck}}});
        } else {
            int newr, newc;
            for(int i=0; i<8; i++){
                newr = rk+disr[i]; newc = ck+disc[i];
                if(valid(newr, newc, rp, cp)){
                    dis[newr][newc][rp] = dis[rk][ck][rp]+1;
                    if(newr==rp && newc==cp) beat=min(beat, dis[newr][newc][rp]);
                    else if(newr-1==rp && newc==cp) stale=min(stale, dis[newr][newc][rp]);
                    else q.push({0, {{rp, cp}, {newr, newc}}});
                }
            }
        }
    }
    if(beat<INT_MAX) cout << "Win in " << beat << " knight move(s).\n";
    else{
        if(stale<INT_MAX) cout << "Stalemate in " << stale << " knight move(s).\n";
        else cout << "Loss in " << loss << " knight move(s).\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL);  cout.tie(NULL);
    cin >> n;
    for(int i=0; i<n; i++){
        memset(dis, -1, sizeof dis);
        cin >> r >> c >> pr >> pc >> kr >> kc;
        if(pr==kr&&pc==kc){
            cout << "Win in " << 0 << " knight move(s).\n";
        } else if(kr-1==pr&&pc==kc){
            cout << "Stalemate in " << 0 << " knight move(s).\n";
        } else bfs();
    }
    
    return 0;
}
