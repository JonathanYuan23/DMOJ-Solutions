#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<char> p(5);
    cin >> p[0] >> p[1] >> p[2] >> p[3] >> p[4];
    cout << count(p.begin(), p.end(), 'P') << "\n";
    return 0;
}
