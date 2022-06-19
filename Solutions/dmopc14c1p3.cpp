#include <bits/stdc++.h>
using namespace std;


int main() {
  double x;
  scanf("%lf", &x);
  double totalscore = 0;
  double totalstudents = x;
  for(int i = 0; i < x; i++){
    int y = 0;
    scanf("%d", &y);
    totalscore += y;
  }
  double g;
  scanf("%lf", &g);
  for(int i = 0; i < g; i++) {
    double y;
    scanf("%lf", &y);
    totalscore += y;
    totalstudents += 1;
    float average = totalscore/totalstudents;
    printf("%.3f\n", average);
  }
}
