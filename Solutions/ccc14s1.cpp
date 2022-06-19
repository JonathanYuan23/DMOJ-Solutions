#include<bits/stdc++.h>

using namespace std;

int main () {

  int k; cin >> k;
  vector <int> nums;

  int num{1};
  for(int i{0}; i<k; i++)
  {
    nums.push_back(num);
    num++;
  }

  int m; cin >> m;

  vector <int> remove;

  for(int i{0}; i<m; i++)
  {
    int r; cin >> r;

    for(int i{0}; i<nums.size(); i++)
    {
      
      if((i+1)%r==0)
        remove.push_back(nums[i]);

    }

    for(int i{0}; i<remove.size(); i++)
    {
      vector<int>::iterator erase;
      erase = find(nums.begin(), nums.end(), remove[i]);

      if(erase!=nums.end())
      {
        nums.erase(erase);
      }
    }

    remove.clear();  
  }

  for(auto n: nums)
    cout << n << endl;
    
  return 0;
}
