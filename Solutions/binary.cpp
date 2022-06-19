//#pragma GCC optimize "Ofast"
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MOD 1000000009
#define p 31
#define INF 0x3f3f3f3f
#define MAXN 500005
#define pb push_back
#define LSB(S) (S & (-S))
typedef vector<int> vi;
typedef vector<vector<int>> vii;


int main()
{
    int q; cin >> q;
    while(q--){
        int n;
        cin >> n;
        string binary = bitset<64>(n).to_string();
        int pos = binary.find_first_of('1');
        int size = 64 - pos;
        if(!n){
            cout << "0000\n";
        }
        else if(size%4==0){
            for(int i=pos, sz=1; i<64; i++, sz++){
                cout << binary[i];
                if(sz%4==0) cout << " ";
            }   cout << "\n";
        }
        else {
            for(; pos>=0; pos--){
                if((64 - pos)%4==0){
                    for(int i=pos, sz=1; i<64; i++, sz++){
                        cout << binary[i];
                        if(sz%4==0) cout << " ";
                    }   cout << "\n";
                    break;
                }
            }
        }
    }
    
    return 0;
}
