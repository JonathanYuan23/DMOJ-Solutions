#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
#define INF 1<<30
using namespace std;
const int MAXN=1005;

int N, M, D, A;
int events[MAXN];

int solve(){

  cin >> N >> M >> D;

  for(int i=0; i<M; i++){cin >> A;  events[A]++;}

  int ans=0, curr=N;
  for(int i=1; i<=D; i++){

    if(curr==0){

      ans++; curr=N; curr--;
      
      if(events[i]>0){curr+=events[i]; N+=events[i];}

    } else {

      curr--;
      
      if(events[i]>0){curr+=events[i]; N+=events[i];}

    }

  }

  return ans;
}

int main(){

  ios_base::sync_with_stdio(0); cin.tie(NULL);  cout.tie(NULL);

  for(int i=0; i<10; i++){

    memset(events, 0, sizeof events);
    cout << solve() << "\n";

  }
  
  return 0;
}
