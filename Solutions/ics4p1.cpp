#include <bits/stdc++.h>
 
using namespace std;

string word;

int main() {

    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.sync_with_stdio(0);
    cout.tie(0);

    cin >> word;

    sort(word.begin(), word.end());

    do{
        cout << word << "\n";
    }while(next_permutation(word.begin(), word.end()));

   return 0;
}
