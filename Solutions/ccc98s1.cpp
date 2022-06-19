#include <bits/stdc++.h>

using namespace std;
 
int main() {

    vector<string> s;
  
    int n;  cin >> n;

    cin.ignore();

    while(n--){

        string sentence, word, newSentence;
        getline(cin, sentence);

        istringstream iss {sentence};

        while(iss >> word){

            if(word.length()==4){
                newSentence+= "**** ";
            }else{
                newSentence+= word + " ";
            }
        }
        
        newSentence.pop_back();
        cout << newSentence << endl << endl;
        
    }

    return 0;
}
