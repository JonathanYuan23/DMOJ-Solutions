#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100010;

int N, K, arr[MAXN], indx[MAXN];

int main()
{
    
  ios_base::sync_with_stdio(0); cin.tie(NULL);  cout.tie(NULL);
  
  cin >> N >> K;

  for(int i{1}; i<=N; i++){
    
    cin >> arr[i];
    indx[arr[i]] = i;

  }

  int i=1;
  while(i<=N && K){

    if(arr[i]==N-i+1){

      i++;
      continue;

    }

    int temp = indx[N-i+1];
    indx[arr[i]] = indx[N-i+1];
    indx[N-i+1] = i;
    swap(arr[temp], arr[i]);

    i++;  K--;
  }

  for(int i{1}; i<=N; i++) 
    cout << arr[i] << " ";
    cout << "\n";
   
  return 0;
}
