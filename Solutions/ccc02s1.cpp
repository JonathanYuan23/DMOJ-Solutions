#include <bits/stdc++.h>
using namespace std;

int main() {
    
    int pink, green, red, orange, goal;
    cin >> pink >> green >> red >> orange >> goal;
    
    int minimum{goal}, count{0};
    for (int p{0}; p <= goal / pink; p++){
      for (int g{0}; g <= goal / green; g++){
        for (int r{0}; r <= goal / red; r++){
          for (int o{0}; o <= goal / orange; o++){
            if ((p * pink) + (g * green) + (r * red) + (o * orange) == goal){
              cout << "# of PINK is " << p << " # of GREEN is " << g << " # of RED is " << r << " # of ORANGE is " << o << endl;
              count++;
              if(p + g + r + o <= minimum){
                minimum = p + g + r + o;
              }
            }
          }
        }
      }
    }
    cout << "Total combinations is " << count << "."<< endl;
    cout << "Minimum number of tickets to print is " << minimum << "." << endl;
    
    return 0;
}
