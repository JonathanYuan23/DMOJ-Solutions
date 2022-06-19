#include<bits/stdc++.h>

using namespace std;

int main () {

  int n;  cin >> n;
  double marks[n];

  for(int i{0}; i<n; i++)
  {
    cin >> marks[i];
  }

  sort(marks, marks+n);

  if(n%2==0)
    cout << round(((marks[n/2-1])+(marks[n/2]))/2);
  if(n%2!=0)
    cout << (marks[n/2]);

  return 0;
}
