#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
#define INF 1<<25
using namespace std;
const int MAXN = 2005;

int N, T, P, solved[MAXN][MAXN], points[MAXN];

vector<pair<int, pair<int, int>>> rankings;

bool comp(const pair<int, pair<int, int>> &a, const pair<int, pair<int, int>> &b){

  if(a.second.first==b.second.first){

    if(a.second.second==b.second.second){

      return a.first<b.first;

    }

    return a.second.second>b.second.second;

  }

  return a.second.first>b.second.first;
}

void pRank(){

  for(int i=0; i<N; i++){

    if(rankings[i].first==P){cout << rankings[i].second.first << " " << i+1 << "\n";  return;}

  }

}

int main(){

	ios_base::sync_with_stdio(false); cin.tie(NULL);  cout.tie(NULL);

  cin >> N >> T >> P;

  for(int i=1; i<=N; i++){
    for(int j=1; j<=T; j++){
    
      cin >> solved[i][j];

      if(!solved[i][j]) points[j]++;

    }
  }

  for(int i=1; i<=N; i++){

    int score=0, problems_solved=0;
    for(int j=1; j<=T; j++){
    
      if(solved[i][j]){problems_solved++; score+=points[j];}

    }

    rankings.push_back({i, {score, problems_solved}});
  }

  sort(rankings.begin(), rankings.end(), comp);

  pRank();

  return 0;
}
