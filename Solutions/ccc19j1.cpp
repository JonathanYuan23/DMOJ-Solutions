#include <bits/stdc++.h>

using namespace std;

int main() {
    
int a, b, c, x, y, z;
int banana, apple;
cin >> a >> b >> c >> x >> y >> z;

apple = (a*3) + (b*2) + c;
banana = (x*3) + (y*2) + z;

if (apple > banana){
  cout <<"A";
}

else if (banana > apple){
  cout << "B";
}

else if (banana == apple){
  cout << "T";
}
    
    return 0;
}
