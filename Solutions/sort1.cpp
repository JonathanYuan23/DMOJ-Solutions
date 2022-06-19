#include <bits/stdc++.h>
#include<bits/stdc++.h>

using namespace std;

int main () {

  vector<int> nums;

  int n;
  cin >> n;
  for(int i{0}; i<n; i++)
  {
    int num;  cin >> num;
    nums.push_back(num);
  }

  for(auto n: nums)
    cout << n << " ";
  cout << endl;
  
  bool swap;
  for(int i=0; i<30; i++)
  {
 
    swap = false;
 
    for(int j=0; j<nums.size()-i-1; j++)
    {
      if(nums[j]>nums[j+1])
      {
        double temp = nums[j];
        nums[j] = nums[j+1];
        nums[j+1] = temp;

        for(auto n: nums)
          cout << n << " ";
        cout << endl;
 
        swap = true;
      }
    }

    if(swap == false)
    {
      break;
    }
  }

  return 0;
}
