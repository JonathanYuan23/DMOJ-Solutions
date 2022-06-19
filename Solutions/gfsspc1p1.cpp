#include <bits/stdc++.h>

using namespace std;

int main() {
    int a, b, c; cin >> a >> b >> c;
    cout << ((a+b>c && a+c>b && b+c>a)?"Huh? A triangle?\n":"Maybe I should go out to sea...\n");
    return 0;
}
