#include <bits/stdc++.h>
using namespace std;

void printTine(int t, int s), printMiddle(int s), printHandle(int s, int h);
int main(){

    int t, s, h; 
    cin >> t >> s >> h;
    printTine(t, s);
    printMiddle(s);
    printHandle(s, h);
    
    return 0;
}

void printTine(int t, int s){
    string spaces{""};
    for(int i{0}; i<s; i++) spaces += " ";
    for (int i{0}; i<t; i++) cout << "*" << spaces << "*" << spaces << "*" << '\n';
}

void printMiddle(int s){
    for (int i{0}; i<(3+s*2); i++) cout << "*";
    cout << '\n';
}

void printHandle(int s, int h){
    for(int i{0}; i<h; i++){
        for(int j{0}; j<(1+s); j++){
            cout << " ";
        }
        cout << "*" << '\n';
    }
}
