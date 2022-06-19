#include<bits/stdc++.h>
using namespace std;

bool dp[30001]; int arr[30];
  
int main()
{

  int n;

  for(int rep{0}; rep<5; rep++){

    memset(dp, 0, sizeof dp);
    dp[0] = true;

    cin >> n;

    int sum=0, w;

    for(int i{0}; i<n; i++){cin >> arr[i], sum+=arr[i];}

    
    for(int i{0}; i<n; i++){

      w = arr[i];

      for(int j=sum-w;  j>=0; j--){

        dp[j+w] |= dp[j];

      }

    }

    for(int i{sum/2}; i>=0; i--){

      if(dp[i]){cout << abs((sum-i)-i) << "\n"; break;}

    }

  }

  return 0;
}
