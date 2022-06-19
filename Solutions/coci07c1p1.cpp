#include <bits/stdc++.h>
using namespace std;

int arrx[1005], arry[1005], x, y;

int main () {

    for(int i=0; i<3; i++){
        cin >> x >> y; 
        arrx[x]++; arry[y]++;
    }
    for(int i=0; i<1005; i++){
        if(arrx[i]==1) x=i;
        if(arry[i]==1) y=i;
    }
    cout << x << " " <<  y << "\n";
    
    return 0;
}
