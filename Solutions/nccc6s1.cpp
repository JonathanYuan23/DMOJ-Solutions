#include <bits/stdc++.h>
using namespace std;

int main() {

  double sum=0; int n;
  cin >> n;

  for (int i{0}; i<n; i++){
    int mark;
    cin >> mark;
    sum+=mark;
  }

  cout << fixed << setprecision (1) << sum/n << "\n";

return 0;
}
