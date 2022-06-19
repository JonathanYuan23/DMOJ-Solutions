#include <bits/stdc++.h>

using namespace std;

void computelps(int patlen, string pat, int lps[]);

int search(string str, string pat){
  
  int strlen = str.length();
  int patlen = pat.length();

  int lps[patlen];

  computelps (patlen, pat, lps);

  int i{0}, j{0};

  while(i < strlen){

    if(pat[j] == str[i]){
      i++;
      j++;
    }if(j == patlen){
      return i-j;
    }else if(i<strlen && pat[j]!=str[i]){

      if(j!=0){
        j = lps[j-1];
      }else{
        i++;
      }

    }

  }
    
  return -1;
}

void computelps(int patlen, string pat, int lps[]){

  lps[0] = 0;

  int len{0}, i{1};

  while(i < patlen){

    if(pat[i] == pat[len]){
      len++;
      lps[i] = len;
      i++;
    }else{

      if(len != 0){
        len = lps[len-1];
      }else{
        lps[i] = 0;
        i++;
      }

    }

  }

}
int main() {

    string S, T;  cin >> S >> T;

    int find = search(S, T);

    cout << find << endl;

    return 0;
}
