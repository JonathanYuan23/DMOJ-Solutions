#include <bits/stdc++.h>
using namespace std;

int main()
{
    
  ios_base::sync_with_stdio(0); cin.tie(NULL);  cout.tie(NULL);
  int n, m; cin >> n >> m;  cout << "All positions change in year " << n << "\n";
  for(int i{n+1}; i<=m; i++)  if((i-n)%4==0 && (i-n)%2==0 && (i-n)%3==0 && (i-n)%5==0)  cout << "All positions change in year " << i << "\n";
  
  return 0;
}
