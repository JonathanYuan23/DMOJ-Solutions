#include <bits/stdc++.h> 
using namespace std; 

int global_count{0};

bool win(string games, int T){

  int scores[4] = {0, 0, 0, 0};

  if(games[0] == 'W')
    scores[0] += 3;
  else if(games[0] == 'L')
    scores[1] += 3;
  else if(games[0] == 'T'){
    scores[0]++;  scores[1]++;
  }

  if(games[1] == 'W')
    scores[0] += 3;
  else if(games[1] == 'L')
    scores[2] += 3;
  else if(games[1] == 'T'){
    scores[0]++;  scores[2]++;
  }

  if(games[2] == 'W')
    scores[0] += 3;
  else if(games[2] == 'L')
    scores[3] += 3;
  else if(games[2] == 'T'){
    scores[0]++;  scores[3]++;
  }

  if(games[3] == 'W')
    scores[1] += 3;
  else if(games[3] == 'L')
    scores[2] += 3;
  else if(games[3] == 'T'){
    scores[1]++;  scores[2]++;
  }

  if(games[4] == 'W')
    scores[1] += 3;
  else if(games[4] == 'L')
    scores[3] += 3;
  else if(games[4] == 'T'){
    scores[1]++;  scores[3]++;
  }

  if(games[5] == 'W')
    scores[2] += 3;
  else if(games[5] == 'L')
    scores[3] += 3;
  else if(games[5] == 'T'){
    scores[2]++;  scores[3]++;
  }
    
  int largest{0}; int countL{0};

  for(int i{0}; i<4; i++){
    if(scores[i]>largest)
      largest = scores[i];
  }

  for(int i{0}; i<4; i++){
    if(scores[i] == largest)
      countL++;
  }

  if(scores[T-1] == largest && countL == 1)
    return true;
  else
    return false;

}

void recurse(string games, int gp, int T){

  if(gp == 6){
    if(win(games, T))
      global_count = global_count+1;
    return;
  }

  int pos = games.find("-");

  games[pos] = 'W';
  recurse(games, gp+1, T);

  games[pos] = 'L';
  recurse(games, gp+1, T);

  games[pos] = 'T';
  recurse(games, gp+1, T);


}

int main() 
{ 

  int T, gp, A, B, Sa, Sb;
  string games = "------";

  cin >> T >> gp;

  for(int i{0}; i<gp; i++){

    cin >> A >> B >> Sa >> Sb;

    if(A == 1 && B == 2){
      if(Sa > Sb)
        games[0] = 'W';
      else if(Sa < Sb)
        games[0] = 'L';
      else if(Sa == Sb)
        games[0] = 'T';
    }
    if(A == 1 && B == 3){
      if(Sa > Sb)
        games[1] = 'W';
      else if(Sa < Sb)
        games[1] = 'L';
      else if(Sa == Sb)
        games[1] = 'T';
    }
    if(A == 1 && B == 4){
      if(Sa > Sb)
        games[2] = 'W';
      else if(Sa < Sb)
        games[2] = 'L';
      else if(Sa == Sb)
        games[2] = 'T';
    }
    if(A == 2 && B == 3){
      if(Sa > Sb)
        games[3] = 'W';
      else if(Sa < Sb)
        games[3] = 'L';
      else if(Sa == Sb)
        games[3] = 'T';
    }
    if(A == 2 && B == 4){
      if(Sa > Sb)
        games[4] = 'W';
      else if(Sa < Sb)
        games[4] = 'L';
      else if(Sa == Sb)
        games[4] = 'T';
    }
    if(A == 3 && B == 4){
      if(Sa > Sb)
        games[5] = 'W';
      else if(Sa < Sb)
        games[5] = 'L';
      else if(Sa == Sb)
        games[5] = 'T';
    }

  }

  recurse(games, gp, T);
  cout << global_count << endl;
  
  return 0; 
}
