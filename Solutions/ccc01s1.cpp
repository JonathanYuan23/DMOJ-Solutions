#include <bits/stdc++.h>
using namespace std;

vector<int> c, d, h, s;
vector<char> C, D, H, S;

int score{0};

int main() {

  int n{0}; char curC, cur;

  while(n < 13){

    cin >> cur;

    if(cur == 'C' || cur == 'D' || cur == 'H' || cur == 'S'){ curC = cur; continue; }

    else if(cur == '2' || cur == '3' || cur == '4' || cur == '5' || cur == '6' || cur == '7' || cur == '8' || cur == '9' || cur == 'T'){

      if(curC == 'C') C.push_back(cur);
      if(curC == 'D') D.push_back(cur);
      if(curC == 'H') H.push_back(cur);
      if(curC == 'S') S.push_back(cur);

      n++;

    }

    else if(cur == 'J' || cur == 'Q' || cur == 'K' || cur == 'A'){

      if(cur == 'J'){
        if(curC == 'C') {C.push_back(cur); c.push_back(1);}
        else if(curC == 'D') {D.push_back(cur); d.push_back(1);}
        else if(curC == 'H') {H.push_back(cur); h.push_back(1);}
        else if(curC == 'S') {S.push_back(cur); s.push_back(1);}
      }
      if(cur == 'Q'){
        if(curC == 'C') {C.push_back(cur); c.push_back(2);}
        else if(curC == 'D') {D.push_back(cur); d.push_back(2);}
        else if(curC == 'H') {H.push_back(cur); h.push_back(2);}
        else if(curC == 'S') {S.push_back(cur); s.push_back(2);}
      }
      if(cur == 'K'){
        if(curC == 'C') {C.push_back(cur); c.push_back(3);}
        else if(curC == 'D') {D.push_back(cur); d.push_back(3);}
        else if(curC == 'H') {H.push_back(cur); h.push_back(3);}
        else if(curC == 'S') {S.push_back(cur); s.push_back(3);}
      }
      if(cur == 'A'){
        if(curC == 'C') {C.push_back(cur); c.push_back(4);}
        else if(curC == 'D') {D.push_back(cur); d.push_back(4);}
        else if(curC == 'H') {H.push_back(cur); h.push_back(4);}
        else if(curC == 'S') {S.push_back(cur); s.push_back(4);}
      }
      n++;
    }

  }

  if(C.size() == 0) c.push_back(3);
  if(C.size() == 1) c.push_back(2);
  if(C.size() == 2) c.push_back(1);

  if(D.size() == 0) d.push_back(3);
  if(D.size() == 1) d.push_back(2);
  if(D.size() == 2) d.push_back(1);

  if(H.size() == 0) h.push_back(3);
  if(H.size() == 1) h.push_back(2);
  if(H.size() == 2) h.push_back(1);

  if(S.size() == 0) s.push_back(3);
  if(S.size() == 1) s.push_back(2);
  if(S.size() == 2) s.push_back(1);

  cout << setw(25) << left << "Cards Dealt" << setw(5) << right << "Points\n";

  int width{30};

  cout << "Clubs "; width -= 6;
  for(auto x: C) cout << left << x << " ";  width -= C.size()*2-1;
  cout << setw(width) << right << accumulate(c.begin(), c.end(), 0) << "\n";
  score += accumulate(c.begin(), c.end(), 0);
  width = 30;

  cout << "Diamonds ";  width -= 9;
  for(auto x: D) cout << left << x << " ";  width -= D.size()*2-1;
  cout << setw(width) << right << accumulate(d.begin(), d.end(), 0) << "\n";
  score += accumulate(d.begin(), d.end(), 0);
  width = 30;

  cout << "Hearts ";  width -= 7;
  for(auto x: H) cout << left << x << " ";  width -= H.size()*2-1;
  cout << setw(width) << right << accumulate(h.begin(), h.end(), 0) << "\n";
  score += accumulate(h.begin(), h.end(), 0);
  width = 30;

  cout << "Spades ";  width -= 7;
  for(auto x: S) cout << left << x << " ";  width -= S.size()*2-1;
  cout << setw(width) << right << accumulate(s.begin(), s.end(), 0) << "\n";
  score += accumulate(s.begin(), s.end(), 0);
  width = 30;

  cout << setw(29) << right << "Total " << setw(6) << left << score << "\n";

  return 0;
}
