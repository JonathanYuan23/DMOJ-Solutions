#include <bits/stdc++.h>
using namespace std;

vector<int> lcpKasai(string s, vector<int>suffix){

  int n = suffix.size(), k = 0;
  vector<int> lcp(n, 0);
  vector<int> inv(n, 0);

  for(int i{0}; i<n; i++)
    inv[suffix[i]] = i;
  
  for(int i{0}; i<n; i++){

    if(inv[i] == n-1){
      k=0;
      continue;
    }

    int j = suffix[inv[i]+1];

    while(i+k<n && j+k<n && s[i+k]==s[j+k])
      k++;

    lcp[inv[i]] = k;
    
    if(k>0)
      k--;

  }

  return lcp;

}

int main(){

  int n, size;  cin >> n;

  string s, temp;
  while(n--){

    cin >> s;

    map<string, int> temp1;
    vector<string> temp2; vector<int> suffix;

    for(int i{0}; i<s.size(); i++){
      temp1[s.substr(i,s.size()-i)] = i;
      temp2.push_back(s.substr(i,s.size()-i));
    }

    sort(temp2.begin(), temp2.end());

    for(int i{0}; i<s.size(); i++)
      suffix.push_back(temp1[temp2[i]]);
    
    vector<int> lcp = lcpKasai(s, suffix);

    int sumLCP = accumulate(lcp.begin(), lcp.end(), 0);
    size = s.size();

    cout << (((size*(size+1))/2) - sumLCP)+1 << endl;
    
  }

  return 0;
}
