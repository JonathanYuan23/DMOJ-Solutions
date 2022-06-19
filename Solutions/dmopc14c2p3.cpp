#include <bits/stdc++.h>

using namespace std;

int main() {

    int N;  cin >> N;
    int *energies = new int[N];
    int *lengths = new int[N];

    int  energy;
    for(int i{0}; i<N; i++){
        cin >> energy;
        energies[i]=energy;
    }
    sort(energies, energies+N);

    int length;
    for(int i{0}; i<N; i++){
        cin >> length;
        lengths[i]=length;
    }
    sort(lengths, lengths+N);

    long sum{0};
    for(int i{0}; i<N; i++)
        sum += energies[i]*lengths[N-1-i];
        

    cout << sum << endl;

    return 0;
}
