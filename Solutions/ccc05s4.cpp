#include<bits/stdc++.h> 
using namespace std; 

unordered_map<string, vector<string>> tree;

int time(string cur){

  if(tree.find(cur)==tree.end())
    return 0;

  int ans = INT_MIN;
  for(int i{0}; i<tree[cur].size(); i++){

    ans = max(ans, 10+time(tree[cur][i]));

  }

  return ans;

}

int main() 
{ 

  int l, n; cin >> l;

  while(l--){

    cin >> n; vector<string> arr(n);

    for(int i{0}; i<n; i++)
      cin >> arr[i];

    string cur = arr[n-1], s;

    for(int i{0}; i<n-1; i++){

      s = arr[i];

      if(tree.find(s)==tree.end()){

        tree[cur].push_back(s);
        cur = s;

      }
      else{

        cur = s;

      }

    }

    cout << (n*10) - (time(arr[n-1])*2) << "\n";
    tree.clear();

  }

	return 0; 
}
