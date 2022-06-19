#include<bits/stdc++.h>
using namespace std;

unordered_map<int, int> wow;

int main()
{

  int n, limit, a, b;  cin >> n;

  vector<int> times(n); vector<int> maxes(n);

  for(int i=0; i<n; i++){

    cin >> a >> b;

    times[i] = a;

    if(b>wow[a])
      wow[a] = b;

  }

  sort(times.begin(), times.end());

  limit = wow[times[0]]; maxes[0] = limit;

  for(int i{1}; i<n; i++){

    if(wow[times[i]]>limit)
      limit = wow[times[i]];

    maxes[i] = limit;

  } 

  int q;  cin >> q;

  vector<int> queries(q);

  int max = 0;
  for(int i=0; i<q; i++){

    cin >> queries[i];

    if(queries[i]>max)
      max = queries[i];

  }

  vector<int> dp(max+1, 0);

  for(int i{1}; i<=max; i++){

    vector<int>::iterator it = upper_bound(times.begin(), times.end(), i);

    dp[i] = maxes[it-times.begin()-1];
    
  }
  
  for(auto x: queries)
    cout << dp[x] << "\n";

  return 0;
}
