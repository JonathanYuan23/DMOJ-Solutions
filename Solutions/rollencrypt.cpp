#include <bits/stdc++.h>
using namespace std;

const string alpha = "abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz";
int freq[26] = { 0 };

int main()
{

  ios_base::sync_with_stdio(0); cin.tie(NULL);  cout.tie(NULL);

  int k;  cin >> k; 
  string s; cin >> s;

  for(int i{0}; i<k; i++){freq[s[i]-'a']++; cout << s[i];}

  int mx = INT_MIN; char mxc;

  for(int i{0}; i<26; i++)
    if(freq[i]>mx){mx=freq[i];  mxc = alpha[i];}

  cout << alpha[(s[k]-'a')+(mxc-'a'+1)];

  for(int i{k+1}; i<s.length(); i++){

    if(freq[s[i-(k+1)]-'a']!=0)
      freq[s[i-(k+1)]-'a']--; 
    
    freq[s[i-1]-'a']++;

    mx = INT_MIN;

    for(int j{0}; j<26; j++)
      if(freq[j]>mx){mx=freq[j];  mxc = alpha[j];}

    cout << alpha[(s[i]-'a')+(mxc-'a'+1)];

  }

  cout << "\n";

  return 0;
}
