#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
#define INF 0x3f3f3f3f
using namespace std;
const int MAXN = 18;

int graph[MAXN][MAXN], dp[MAXN][1<<MAXN], N, M, s, d, l;

int solve(int v, int mask){

  if(v==N-1) return 0;

  if(dp[v][mask]!=-1) return dp[v][mask];

  int ans = INT_MIN;

  for(int i=0; i<N; i++){

    if((mask & 1<<i)!=0 || graph[v][i]==0) continue;

    ans = max(ans, solve(i, mask|1<<i)+graph[v][i]);

  }

  return dp[v][mask]=ans;
}

int main(){

	ios_base::sync_with_stdio(0); cin.tie(NULL);  cout.tie(NULL);

  cin >> N >> M;

  for(int i=0; i<M; i++){

    cin >> s >> d >> l;

    graph[s][d] = l;

  }
  
  memset(dp, -1, sizeof dp);
  cout << solve(0, 1) << "\n";
  
  return 0;
}
