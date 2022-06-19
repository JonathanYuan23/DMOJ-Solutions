#include <bits/stdc++.h>

using namespace std;

int main() {
    
int num, shift, n=0, sum=0;

cin>> num >> shift;

while(n<=shift){
sum+=num;
num = num*10;
n++;
}

cout << sum;
    
    return 0;
}
