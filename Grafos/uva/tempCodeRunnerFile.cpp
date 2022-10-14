#include <bits/stdc++.h>
using namespace std;

int main(){
    int tc;
    string s, vertices;
    scanf("%d\n", &tc);
    while(tc--){
        
        int V=0, E=0, acorns=0;
        vector<bool> connected(26, false);
        while(getline(cin, s)){
            if(s[0] == '*') break;
            char e1, e2;
            sscanf(s.c_str(), "(%c,%c)", &e1, &e2);
            
            connected[e1-'A'] = true;
            connected[e2-'A'] = true;
            E++;
            cout<<"entro";
        }
        getline(cin, vertices);
        for(auto elem: vertices){
            if(elem != ','){
                if(!connected[elem-'A']) acorns++;
                V++;
            }
            
        }
        //cout<<V<<" "<<E<<" "<<acorns;
        printf("There are %d tree(s) and %d acorn(s).\n", V-E-acorns, acorns);
    }
    
    return 0;
}