#include <bits/stdc++.h>

using namespace std;

int main() {

  vector<double> streams;

  int n;  cin >> n;

  double stream;

  while(n--){
    cin >> stream;  streams.push_back(stream);
  }

  int decision, pos, percentage;

  double temp;

  for(;;){

    cin >> decision;

    if(decision == 99){
      cin >> pos; cin >> percentage;

      streams.insert(streams.begin()+pos-1, streams[pos-1]);

      temp = streams[pos-1];

      streams[pos-1] = (temp * percentage)/100.0;

      streams[pos] = (temp * (100-percentage))/100.0;
    }

    if(decision == 88){
      cin >> pos;

      streams[pos-1] += streams[pos];

      streams.erase(streams.begin()+pos);
    }

    if(decision == 77)
      break;

  }

  for(auto x: streams)
    cout << x << " ";
  cout << "\n";

  return 0;
}
