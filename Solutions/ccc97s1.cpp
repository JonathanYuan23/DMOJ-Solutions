#include <bits/stdc++.h>

using namespace std;

int main() {

    int n;  cin >> n;

    for(int i{0}; i<n; i++){
        
        vector<string> subjects;
        vector<string> verbs;
        vector<string> objects;
        vector<string> output;

        int s, v, o;    cin >> s >> v >> o;

        cin.ignore();

        for(int j{0}; j<s; j++){
            string temp;    getline(cin, temp);
            subjects.push_back(temp);
        }
        for(int j{0}; j<v; j++){
            string temp;    getline(cin, temp);
            verbs.push_back(temp);
        }
        for(int j{0}; j<o; j++){
            string temp;    getline(cin, temp);
            objects.push_back(temp);
        }

        for(int j{0}; j<subjects.size(); j++){
            for(int k{0}; k<verbs.size(); k++){
                for(int l{0}; l<objects.size(); l++){
                    string temp = subjects[j] + " " + verbs[k] + " " + objects[l] + ".";

                    output.push_back(temp);
                }
            }
        }

        bool swap;
        for(int i=0; i<output.size(); i++)
        {
 
            swap = false;
 
            for(int j=0; j<output.size()-i-1; j++)
            {
                if(output[j].compare(output[j+1])==1 || 
                output[j].compare(output[j+1])==0)
                {
                    output[j].swap(output[j+1]);

                    swap = true;
                }
            }

            if(swap == false)
            {
                break;
            }
        }

        for(auto n: output)
            cout << n << endl;

    }

    return 0;
}
