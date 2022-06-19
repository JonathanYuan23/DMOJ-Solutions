#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
#define INF 1<<25
using namespace std;
const int MAXN = 2005;

int N, M, A;

vector<int> parking_spaces(105), car_weights(MAXN); //prices
priority_queue<int, vector<int>, greater<int>> mn_space;  queue<int> cars;  //spaces available and the queue of cars
unordered_map<int, int> space_occupied; //keeps track of the spaces the cars occupy

int main(){

	ios_base::sync_with_stdio(false); cin.tie(NULL);  cout.tie(NULL);

  cin >> N >> M;  for(int i=0; i<N; i++){mn_space.push(i); cin >> parking_spaces[i];}

  for(int i=1; i<=M; i++){cin >> car_weights[i];}

  int ans=0;
  for(int i=0; i<2*M; i++){

    cin >> A;

    if(A>0){

      if(mn_space.empty()) cars.push(A);
      else{

        int space = mn_space.top(); mn_space.pop();
        space_occupied[A] = space;
        ans+=car_weights[A]*parking_spaces[space];

      }

    } else {

      mn_space.push(space_occupied[abs(A)]);

      if(!cars.empty()){

        int car = cars.front(), space = mn_space.top(); cars.pop(); mn_space.pop();
        space_occupied[car] = space;
        ans+=car_weights[car]*parking_spaces[space];

      }

    }

  }

  cout << ans << "\n";

  return 0;
}
