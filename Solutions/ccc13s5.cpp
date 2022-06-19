#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize "Ofast"
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define fi first
#define se second
#define INF 0x3f3f3f3f
#define MAX 5000005
#define pb push_back
#define LSB(S) (S & (-S))
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<piii> viii;

int N;
bool sieve[MAX];

void primes(){
    memset(sieve, 1, sizeof sieve);
    for(int i=2; i*i<=N; i++){
        if(sieve[i]){
            for(int j=i*i; j<=N; j+=i) sieve[j]=0;
        }
    }
}


void solve(){
    ll sum=0;
    for(;;){
        if(N==1) break;
        if(sieve[N]){
            N--;
            sum+=N;
        } else {
            if(N%2==0){
                N/=2;
                sum++;
            } else {
                int factor, add;
                for(int i=2; i*i<=N; i++){
                    if(N%i==0){
                        factor=i;
                        break;
                    }
                }
                add=N/factor;
                N-=add;
                sum+=(N/add);
            }
        }
    }
    cout << sum << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL);  cout.tie(NULL);
    cin >> N;
    primes();
    solve();
     
    return 0;
}
