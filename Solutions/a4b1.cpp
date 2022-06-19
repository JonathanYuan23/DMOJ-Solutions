#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;
    vector<int> ar(n);
    for(int i=0; i<n; i++) cin >> ar[i];
    sort(ar.begin(), ar.end());
    for(auto x: ar) cout << x << "\n";
    return 0;
}
