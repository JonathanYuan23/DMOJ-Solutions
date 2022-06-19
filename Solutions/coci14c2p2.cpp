#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
#define INF 1<<30
using namespace std;
typedef vector<int> vi;
const int MAXN=100005;

int n, t[MAXN], r[MAXN];  string s;

int main(){

  ios_base::sync_with_stdio(0); cin.tie(NULL);  cout.tie(NULL);

  unordered_map<string, int> finished;

  cin >> n;

  for(int i=0; i<n; i++){ cin >> s; if(finished.find(s)==finished.end()) finished[s]=i; t[finished[s]]++;}
  for(int i=0; i<n-1; i++){ cin >> s; r[finished[s]]++; }
  for(auto x: finished){if(t[x.second]!=r[x.second]){cout << x.first << "\n"; break;}}

  return 0;
}
