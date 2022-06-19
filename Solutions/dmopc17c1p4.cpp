#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int MAXN = 5001;
const int INF = 0x3f3f3f3f;
ll dp[2][MAXN], indx=0, N, H;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);  cout.tie(NULL);

  cin >> N >> H;

  for(int i=0; i<N; i++){

    int next = !indx;

    ll g, h, q, t;

    cin >> g >> h >> q >> t;

    for(int j=0; j<=H; j++){

      dp[next][j] = -INF;

      if(j>=h)
        dp[next][j] = max(dp[next][j], dp[indx][j-h]+g);

      if(j>=t+h)
        dp[next][j] = max(dp[next][j], dp[next][j-t]+q);

    }

    for(int j=0; j<=H; j++)
      dp[next][j] = max(dp[next][j], dp[indx][j]);
    
    indx = next;

  }

  cout << dp[indx][H] << "\n";
	
  return 0;
}
