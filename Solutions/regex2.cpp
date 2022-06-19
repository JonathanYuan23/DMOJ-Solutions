#include <bits/stdc++.h>

using namespace std;
 
int main() {

    int n;  scanf("%i", &n);

    cin.ignore();

    regex regexp ("\\b\\w{4}\\b");

    string str;
    while(n--){
        getline(cin, str);

        cout << regex_replace(str, regexp, "****") << endl; 
    }
   
    return 0;
}
