#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
#define INF 1<<30
using namespace std;
const int MAXN = 2005;

vector<pair<int, int>> art(MAXN); int DP[MAXN][MAXN], Hx, Hy, Ax, Ay, N;

int dist(int x1, int y1, int x2, int y2){

  return abs(x1-x2) + abs(y1-y2);

}

int solve(int i, int resting){

  if(i==N) return 0;

  if(DP[i][resting]!=-1)  return DP[i][resting];

  int useActive, useResting;

  useActive = dist(art[i-1].first, art[i-1].second, art[i].first, art[i].second);
  useResting = dist(art[resting].first, art[resting].second, art[i].first, art[i].second);

  DP[i][resting] = min(useActive+solve(i+1, resting), useResting+solve(i+1, i-1));

  return DP[i][resting];
}

int main(){

  ios_base::sync_with_stdio(0); cin.tie(NULL);  cout.tie(NULL);
  
  cin >> N >> Hx >> Hy >> Ax >> Ay;

  int x, y, indx;

  for(int i=0; i<N; i++){

    cin >> x >> y;

    art[i] = {x, y};

  }

  N++;

  int dist1 = dist(Hx, Hy, art[0].first, art[0].second), dist2 = dist(Ax, Ay, art[0].first, art[0].second), res=INF;

  memset(DP, -1, sizeof DP);
  art.insert(art.begin(), {Hx, Hy});
  res = min(res, solve(2, 0)+dist2);

  memset(DP, -1, sizeof DP);
  art[0] = {Ax, Ay};
  res = min(res, solve(2, 0)+dist1);

  cout << res << "\n";
    
  return 0;
}
