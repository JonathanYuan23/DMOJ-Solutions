#include <bits/stdc++.h>
using namespace std;

int main() {

    int n;  cin >> n;
    cin.ignore();

    for(int i{0}; i<n; i++){

        vector<string> syllables;

        string s1;
        getline(cin, s1);
        string s2;
        getline(cin, s2);
        string s3;
        getline(cin, s3);
        string s4;
        getline(cin, s4);

        int blank = s1.find_last_of(" ");
        if(blank != string::npos)
            s1 = s1.substr(blank+1, s1.length()-blank-1);
        syllables.push_back(s1);

        blank = s2.find_last_of(" ");
        if(blank != string::npos)
            s2 = s2.substr(blank+1, s2.length()-blank-1);
        syllables.push_back(s2);

        blank = s3.find_last_of(" ");
        if(blank != string::npos)
            s3 = s3.substr(blank+1, s3.length()-blank-1);
        syllables.push_back(s3);

        blank = s4.find_last_of(" ");
        if(blank != string::npos)
            s4 = s4.substr(blank+1, s4.length()-blank-1);
        syllables.push_back(s4);

        for(int j{0}; j<syllables.size(); j++){
            int size = syllables[j].length()-1, pos;
            bool vowel{false};

            for(int k{size}; k>=0; k--){
                char letter = syllables[j][k];
                if(letter=='a'||letter=='e'||letter=='i'||letter=='o'||letter=='u'||letter=='A'||letter=='E'||letter=='I'||letter=='O'||letter=='U'){
                    pos=k;
                    vowel=true;
                    break;
                }                
            }

            if(vowel){
                string temp;
                for(int k{pos}; k<=size; k++)
                    temp+=tolower(syllables[j][k]);

                syllables[j]=temp;
            }       
        }

        if(syllables[0]==syllables[1]&&syllables[1]==syllables[2]&&syllables[2]==syllables[3])
            cout << "perfect\n";
        else if(syllables[0]==syllables[1]&&syllables[2]==syllables[3])
            cout << "even\n";
        else if(syllables[0]==syllables[2]&&syllables[1]==syllables[3])
            cout << "cross\n";
        else if(syllables[0]==syllables[3]&&syllables[1]==syllables[2])
            cout << "shell\n";
        else
            cout << "free\n";

    }

    return 0;
}
