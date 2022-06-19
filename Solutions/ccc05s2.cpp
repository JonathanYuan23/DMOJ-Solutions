#include <bits/stdc++.h>
using namespace std;

void readjust(int &x, int &y, int c, int r){

  if(x<0) x=0;
  if(x>c) x=c;
  if(y<0) y=0;
  if(y>r) y=r;

}

int main()
{

  int c, r; cin >> c >> r;

  int x, y, curx=0, cury=0; cin >> x >> y;

  while(!(x==0 && y==0)){

    curx+=x;  cury+=y;

    readjust(curx, cury, c, r);

    cout << curx << " " << cury << "\n";

    cin >> x >> y;

  }

  return 0;
}
