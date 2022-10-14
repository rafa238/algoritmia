#include <bits/stdc++.h>

using namespace std;

int positiveAnswersCount(int N, int Q, string blockCharacters, vector<int> L, vector<int> R){
    int ans = 0;
    for(int i=0; i<Q; i++){    
        int pos[26] = {0};
        for(int j=L[i]-1; j<R[i]; j++){
            pos[blockCharacters[j]-'A'] += 1;
        }
        //comprobamos si es o no par para contar el caso en el que vamos a contar
        int contimp=0;
        for(int j=0; j<26; j++){
            if(pos[j]%2 != 0) contimp++;
        }
        if((R[i] - L[i] + 1)%2 == 0){
            if(contimp == 0) ans+=1; 
        } else {
            if(contimp <= 1) ans+=1;  
        }
    }
    return ans;
}

int main(){
    int T;
    // Get number of test cases
    cin >> T;
    for (int tc = 1; tc <= T; tc++){
        int N, Q;
        // Get number of blocks and number of questions
        cin >> N >> Q;

        string blockCharacters;
        // Get the string representing the characters on the blocks
        cin >> blockCharacters;

        vector<int> L(Q), R(Q);
        for (int i = 0; i < Q; i++){
            cin >> L[i] >> R[i];
        }

        cout << "Case #" << tc << ": "
             << positiveAnswersCount(N, Q, blockCharacters, L, R) << endl;
    }
    return 0;
}