#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
#define INF 0x3f3f3f3f
using namespace std;
const int MAXN = 1000000;

ll n, w, mn=0, mx=0; vector<ll> foods;

void find_min(){

  auto it = upper_bound(foods.begin(), foods.end(), w);

  ll prev = w;
  if(it==foods.end()){

    for(int i=n-1; i>=0; i--){

      mn+= min(abs(prev-foods[i]), abs(w-foods[i]));
      prev=foods[i];

    }

  }
  else{

    int dist = distance(foods.begin(), it);

    prev=w;
    for(int i=dist-1; i>=0; i--){

      mn+= min(abs(prev-foods[i]), abs(w-foods[i]));
      prev=foods[i];

    }

    prev=w;
    for(int i=dist; i<n; i++){

      mn+= min(abs(prev-foods[i]), abs(w-foods[i]));
      prev=foods[i];

    }
    
  }

}

void find_mx(){

  ll l=0, r=n-1, mxl=0, mxr=0;

  ll next, prev=w, cur=0;

  while(l<=r){

    cur==0 ? next=l : next=r;

    mxl += max(abs(w-foods[next]), abs(prev-foods[next]));
    
    prev = foods[next];

    cur==0 ? l++ : r--;
    cur ^= 1;

  }

  prev=w; cur=0, l=0, r=n-1;

  while(l<=r){

    cur==0 ? next=r : next=l;

    mxr += max(abs(w-foods[next]), abs(prev-foods[next]));

    prev = foods[next];

    cur==0 ? r-- : l++;
    cur ^= 1;

  }

  mx = max(mxl, mxr);

}

int main(){

	ios_base::sync_with_stdio(0); cin.tie(NULL);  cout.tie(NULL);

  cin >> n >> w;

  foods.resize(n);

  for(int i=0; i<n; i++) cin >> foods[i];

  sort(foods.begin(), foods.end());

  find_min(); find_mx();

  cout << mn << " " << mx << "\n";
  
  return 0;
}
