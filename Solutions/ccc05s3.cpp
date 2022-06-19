#include <bits/stdc++.h>
using namespace std;

int tensor[1024][1024], temp1[1024][1024], temp2[1024][1024];

void solve(int mp, int nq){

  int mn=INT_MAX, mx=INT_MIN;

  for(int i{0}; i<mp; i++){
    for(int j{0}; j<nq; j++){

      if(tensor[i][j]>mx)
        mx = tensor[i][j];

      if(tensor[i][j]<mn)
        mn = tensor[i][j];

    }
  }

  cout << mx << "\n" << mn << "\n";
  mn=INT_MAX, mx=INT_MIN;

  for(int i{0}; i<mp; i++){

    if(accumulate(tensor[i], tensor[i]+nq, 0)>mx)
      mx = accumulate(tensor[i], tensor[i]+nq, 0);

    if(accumulate(tensor[i], tensor[i]+nq, 0)<mn)
      mn = accumulate(tensor[i], tensor[i]+nq, 0);

  }

  cout << mx << "\n" << mn << "\n";
  mn=INT_MAX, mx=INT_MIN;

  int sum;
  for(int j{0}; j<nq; j++){

    sum=0;
    for(int i{0}; i<mp; i++){

      sum+=tensor[i][j];

    }

    if(sum>mx)
      mx = sum;

    if(sum<mn)
      mn = sum;
  }

  cout << mx << "\n" << mn << "\n";

  return;
}

int main()
{

  int n, row, col, p, q;  cin >> n >> row >> col;

  int mp=row, nq=col;

  for(int i{0}; i<row; i++)
    for(int j{0}; j<col; j++)
      cin >> temp1[i][j];
    
  for(int i{0}; i<n-1; i++){

    cin >> p >> q;

    mp*=p;  nq*=q;

    for(int i{0}; i<p; i++)
      for(int j{0}; j<q; j++)
        cin >> temp2[i][j];

    int a=0, b=0, c=0, d=0, e=0;

    for(int i{0}; i<mp; i++){
      for(int j{0}; j<nq; j++){

        tensor[i][j] = temp1[a][b] * temp2[c][d];

        if(j<nq-1 && d<q-1) d++;

        else if(j<nq-1 && d==q-1){  d=0;  b++;  }

        else if(j==nq-1 && e<p-1){  c++;  b=0;  d=0;  e++;  }

        else if(j==nq-1 && e==p-1){ c=0;  a++;  b=0;  c=0;  d=0;  e=0;  }

      }
    }

    for(int i{0}; i<mp; i++)
      for(int j{0}; j<nq; j++)
        temp1[i][j] = tensor[i][j];

  }

  solve(mp, nq);

  return 0;
}
