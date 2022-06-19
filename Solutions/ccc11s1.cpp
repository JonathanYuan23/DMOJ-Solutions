#include <bits/stdc++.h>
using namespace std;

int main() {

    int n;  cin >> n;
    int tCount{0}, sCount{0};

    cin.ignore();

    for(int i{0}; i<n; i++){

        string s;
        getline(cin, s);

        char c;
        istringstream iss{s};

        while(iss >> c){
            if(c=='s'||c=='S')
                sCount++;
            if(c=='t'||c=='T')
                tCount++;
        }

    }

    if(tCount > sCount)
        cout << "English\n";
    if(tCount < sCount)
        cout << "French\n";
    if(tCount == sCount)
        cout << "French\n";

    return 0;
}
