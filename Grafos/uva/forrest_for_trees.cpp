#include <bits/stdc++.h>
using namespace std;

int main(){
    int tc;
    cin >> tc;
    while (tc--){
        vector<bool> connected(26, 0);
        int V = 0, E = 0, acorns = 0;
        string s, vertices;
        while (cin >> s){
            if (s[0] == '*') break;
            connected[s[1] - 'A'] = true;
            connected[s[3] - 'A'] = true;
            E++;
        }
        cin >> vertices;
        for (auto elem : vertices){
            if (elem != ','){
                if (!connected[elem - 'A']) acorns++;
                V++;
            }
        }
        printf("There are %d tree(s) and %d acorn(s).\n", V - E - acorns, acorns);
    }
    return 0;
}