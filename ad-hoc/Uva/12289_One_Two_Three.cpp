#include<bits/stdc++.h>
using namespace std;

vector<char> unov = {'o', 'n', 'e'};
vector<char> dosv = {'t', 'w', 'o'};

int main(){
    int tc; cin>>tc;
    string word;
    while(tc--){
        int one, two;
        one = two = 0;
        cin >> word;
        
        if(word.size() != 3){    
            cout << "3" << endl;
            continue;
        }
        for(int i=0; i<3; i++){
            if(unov[i] == word[i]){
                one++;
            } else {
                two++;
            }
        }
        cout<<((one>two) ? "1" : "2")<<endl;
    }
    return 0;
}