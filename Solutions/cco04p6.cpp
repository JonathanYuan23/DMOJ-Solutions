#pragma GCC optimize "Ofast"
#include <bits/stdc++.h>
using namespace std; using pii = pair<int, int>;  using piii = pair<int, pii>;  using piiii = pair<pii, pii>;  using vi = vector<int>;  using vii = vector<pii>;  using viii = vector<piii>;  using viiii = vector<piiii>; using ll = long long; using ull = unsigned long long; 
#define frein freopen("input.txt", "r", stdin)
#define freout freopen("output.txt", "w", stdout)
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define pf push_front
#define ppb pop_back
#define LSB(x) (x & (-x))
#define sz(x) (int)(x.size())
#define ms(a, b) memset(a, b, sizeof a)

const int MOD = 1000000007, INF = 0x3f3f3f3f, MX = 1<<20, IMX = INT_MAX, IMN = INT_MIN;
const long long LLMX = LONG_LONG_MAX, LLMN = LONG_LONG_MIN;
const char nl = '\n';

/*
        ans = max(
                    min(
                            for(i=1...10 in lead's deck) 
                                for(j=1...10 in opponent's deck)
                                    if(win) 1 + rec(lead, mask | cardi | cardj, left - 1)
                                    else left - 1 - rec(!lead, mask | cardi | cardj, left - 1)
                        )
                )
*/

string types = "BGRY";
int dp[2][MX], psa[2][5];
vi cards[2][5];

int get(int lead, int type, int i){
    if(lead) 
        return psa[0][4] + psa[1][type-1] + i;
    else 
        return psa[0][type-1] + i;
}

int rec(int lead, int mask, int roundsleft){
    if(!roundsleft) 
        return 0;
    if(dp[lead][mask] != -1) 
        return dp[lead][mask];
    int ans = 0, temp;
    // check each card type
    for(int i=0; i<4; i++){
        // card lead chooses
        for(int j=0; j<sz(cards[lead][i]); j++){
            int pos = get(lead, i+1, j);
            if(mask & 1 << pos) 
                continue;
            temp = INF;
            // check if opponent has cards of same type
            for(int k=0; k<sz(cards[!lead][i]); k++){
                int pos2 = get(!lead, i+1, k);
                if(mask & 1 << pos2) 
                    continue;
                // lead wins
                if(cards[lead][i][j] > cards[!lead][i][k]) 
                    temp = min(temp, 1 + rec(lead, mask | (1<<pos) | (1<<pos2), roundsleft - 1));
                // opponent wins
                else 
                    temp = min(temp, roundsleft - 1 - rec(!lead, mask | (1<<pos) | (1<<pos2), roundsleft - 1));
            }
            // opponent has none of the same type
            if(temp == INF){
                // opponent can choose any card type
                for(int k=0; k<4; k++){
                    for(int l=0; l<sz(cards[!lead][k]); l++){
                        int pos2 = get(!lead, k+1, l);
                        if(mask & 1 << pos2) 
                            continue;
                        // lead wins
                        temp = min(temp, 1 + rec(lead, mask | (1<<pos) | (1<<pos2), roundsleft - 1));
                    }
                }
            }
            ans = max(ans, temp);
        }
    }
    return dp[lead][mask] = ans;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL);  cout.tie(NULL); 
    while(1){
        for(int i=0; i<10; i++){
            char type, val; 
            cin >> type >> val;
            if(type == '*') 
                return 0;
            cards[0][types.find(type)].pb(val - '0');
        }
        for(int i=0; i<4; i++) 
            for(int j=1; j<=5; j++) 
                if(find(cards[0][i].begin(), cards[0][i].end(), j) == cards[0][i].end()) 
                    cards[1][i].pb(j);
        for(int i=1; i<=4; i++) {
            psa[0][i] = psa[0][i-1] + sz(cards[0][i-1]); 
            psa[1][i] = psa[1][i-1] + sz(cards[1][i-1]);
        }
        ms(dp, -1);
        cout << rec(0, 0, 10) << nl;
        for(int i=0; i<5; i++){
            cards[0][i].clear(); 
            cards[1][i].clear();
        }
    }
    return 0;
}
