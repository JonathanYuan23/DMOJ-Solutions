#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
#define INF 1<<30
using namespace std;
const int MAXN = 35;

string base="Good writing is good writing is good writing.";
string pre="Good writing is good ", mid=" writing is good ", suf=" is good writing.";

int Q, level, indx; ll len[MAXN];

char combi(int level, int idx){

  if(level==0) return base[idx];

  if(idx < pre.length()) return pre[idx];
  idx-=pre.length();

  if(idx < len[level-1]) return combi(level-1, idx);
  idx-=len[level-1];

  if(idx < mid.length()) return mid[idx];
  idx-=mid.length();

  if(idx < len[level-1]) return combi(level-1, idx);
  idx-=len[level-1];

  return suf[idx];  
}

int main(){

	ios_base::sync_with_stdio(0); cin.tie(NULL);  cout.tie(NULL);
  
  len[0]=base.length();

  for(int i=1; i<=30 ; i++)
    len[i] = pre.length() + len[i-1] + mid.length() + len[i-1] + suf.length();

  cin >> Q;

  for(int i=0; i<Q; i++){

    cin >> level >> indx; indx--;

    if(indx>=len[level]) cout << ".\n";
    else cout << combi(level, indx) << "\n";

  }
  
  return 0;
}
