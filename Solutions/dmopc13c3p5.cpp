#include <bits/stdc++.h> 
using namespace std; 

unordered_map<string, int> lookup;

int sol(int curTime, int curFood, int value[], int time[], int food[], int n){

  if(curTime<=0 || curFood<=0 || n==0){
    return 0;
  }

  if(time[n-1]>curTime || food[n-1]>curFood){
    return sol(curTime, curFood, value, time, food, n-1);
  }

  string key = to_string(n) + "|" + to_string(curTime) + "|" + to_string(curFood);

  if(lookup.find(key) == lookup.end()){

    lookup[key] =  max(value[n-1] + sol(curTime-time[n-1], curFood-food[n-1], value,time, food, n-1), sol(curTime, curFood, value, time, food, n-1));

  }

  return lookup[key];
}
  
int main() 
{ 

  int M, U, R;  cin >> M >> U >> R;

  int time[R], food[R], value[R];

  for(int i{0}; i<R; i++)
    cin >> value[i] >> time[i] >> food[i];
  
  int val = sol(M, U, value, time, food, R);

  cout << val << endl;

  return 0; 
}
