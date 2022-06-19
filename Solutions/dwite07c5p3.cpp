#pragma GCC optimize "Ofast"
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);  cout.tie(0);
    for(int i=0, a; i<5; i++) {
        cin >> a;
        cout << ( __builtin_popcount (a) % 2 == 0  ? 0 : 1) << '\n';
    }
}
