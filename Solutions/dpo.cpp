#include <bits/stdc++.h>
#define MOD 1000000007
#define ll long long
using namespace std;
const int MAXN = 2100000;

int n, mx, matches[22][22], dp[22][MAXN];

int main(){
	
  ios_base::sync_with_stdio(0); cin.tie(NULL);  cout.tie(NULL);
	
  cin >> n; 	mx = 1 << n;

	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			cin >> matches[i][j];
		
	dp[0][0] = 1;
	for(int i = 0; i < n; i++){
		for(int mask = 0; mask < mx; mask++){
			if(__builtin_popcount(mask) == i){
				for(int j = 0; j < n; j++){
					if(matches[i][j] && !(mask & 1 << j)){
						dp[i + 1][mask | 1 << j] += dp[i][mask];
            dp[i + 1][mask | 1 << j] %= MOD;
					}
				}
			}
		}
	}
	
  cout << dp[n][mx-1] << "\n";

	return 0;
}
