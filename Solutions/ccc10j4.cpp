#include <bits/stdc++.h>
using namespace std;

vector<int> diffs, nums;

bool cycle(vector<int> temp, int index){

  int i=0, j=index;

  while(i<temp.size() && j<diffs.size())
  {
    if(temp[i]!=diffs[j]) return false;
    i++;  j++;
  }

  return true;
}

bool all_same(vector<int> diffs)
{
  for(int i{0}; i<diffs.size(); i++)  if(diffs[i]!=diffs[0])  return false;
  return true;
}

void solve(){

  if(nums.size()==1){cout << 0 << "\n"; return;}
  if(nums.size()==2){cout << 1 << "\n"; return;}
  if(nums.size()==3){cout << ((nums[1]-nums[0]==nums[2]-nums[1]) ? 1 : 2) << "\n";  return;}

  for(int i{1}; i<nums.size();  i++)  diffs.push_back(nums[i]-nums[i-1]);

  if(all_same(diffs)){cout << 1 << "\n";  return;}

  int mn = INT_MAX; vector<int> temp;

  for(int i{1}; i<diffs.size(); i++)
  {
    for(int j{0}; j<=i; j++)  temp.push_back(diffs[j]);

    if(cycle(temp, i+1))  if(temp.size()<mn)  mn = temp.size(); temp.clear();

  } cout << mn << "\n";
}

int main()
{

  ios_base::sync_with_stdio(0); cin.tie(NULL);  cout.tie(NULL);
  int n, temp;  cin >> n;

  while(n!=0)
  {
    for(int i{0}; i<n; i++){cin >> temp;  nums.push_back(temp);}
    solve();  cin >> n;
    nums.clear(); diffs.clear();
  }

  return 0;
}
