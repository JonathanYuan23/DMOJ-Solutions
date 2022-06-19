#include <bits/stdc++.h>
using namespace std;

unordered_map<char, int> count1, count2;

int main() {
    string s1, s2; 
    cin >> s1 >> s2;
    for(auto x: s2) count2[x]++;
    for(auto x: s1) count1[x]++;
    for(auto x: count1){
        if(x.second != count2[x.first]){
            cout << x.first << "\n";
            break;
        }
    }
    return 0;
}
