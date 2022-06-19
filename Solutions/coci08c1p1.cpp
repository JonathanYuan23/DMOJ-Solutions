#include <bits/stdc++.h>
using namespace std;

int main () {
    vector<int> arr(3);
    cin >> arr[0] >> arr[1] >> arr[2];
    int l, r, count=0;
    for(;;){
        sort(arr.begin(), arr.end());
        l = arr[1]-arr[0]; r = arr[2]-arr[1];
        if(l==1 && r==1) break;
        if(l>=r){
            arr[2]=arr[1]-1;
        } else {
            arr[0]=arr[2]-1;
        }
        count++;
    }
    cout << count << "\n";
    return 0;
}
