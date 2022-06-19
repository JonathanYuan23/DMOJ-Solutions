#include<bits/stdc++.h>

using namespace std;

int main () {

  int n;  cin >> n;

  vector <int> xyene;
  vector <int> eagle;

  for(int i{0}; i<n; i++)
    {
      int num;  cin >> num;
      xyene.push_back(num);
    }

  for(int i{0}; i<n; i++)
    {
      int num;  cin >> num;
      eagle.push_back(num);
    }

  int xyenePoints{0}, eaglePoints{0};

  for(int i{0}; i<n; i++)
  {
    if(xyene[i]>eagle[i])
      xyenePoints++;
    if(eagle[i]>xyene[i])
      eaglePoints++;
  }

    cout << xyenePoints << " " << eaglePoints << endl;

    if(xyenePoints>eaglePoints)
      cout << "Xyene";
    if(eaglePoints>xyenePoints)
      cout << "FatalEagle";
    if(eaglePoints==xyenePoints) 
      cout << "Tie";

  return 0;
}
