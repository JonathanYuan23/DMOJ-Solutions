#include <bits/stdc++.h>

using namespace std;

int main() {
    
int N, D, Q, L, T;
int salary;

cin >> N >> D >> Q >> L >> T;

N = N * 5;
D = D * 10;
Q = Q * 25;
L = L * 100;
T = T * 200;

salary = N + D + Q + L + T;

cout << salary << endl;
    return 0;
}
