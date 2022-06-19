#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(0); cin.tie(NULL);  cout.tie(NULL);

    int n;  cin >> n;

    while(n--){
        string s;   cin >> s;

        int mcount=0, ccount=0;
        for(auto x: s){
            if(x=='M') mcount++;
            if(x=='C') ccount++;
        }

        if(mcount==0 && ccount==0) cout << "PASS\n";
        else if(mcount==1 && ccount==0) cout << "FAIL\n";
        else if(mcount==0 && ccount==1) cout << "FAIL\n";
        else if(mcount>=1 && ccount>=1) cout << "NEGATIVE MARKS\n";
    }
    
    return 0;
}
