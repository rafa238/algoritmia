#include <bits/stdc++.h>
using namespace std;

void mySplit(string cad, vector<pair<string, string>> &aut_title){
    int indice = cad.find('"', 2);
    //cout<<cad.substr(1, indice-1)<<endl;
    //cout<<cad.substr(indice+5, cad.size()-1)<<endl;
    aut_title.push_back(make_pair(cad.substr(indice+5, cad.size()-1), cad.substr(1, indice-1)));
}

int main(){
    char tem[85];
    map<string, int> positions;
    vector<pair<string, string>> aut_title;
    string cad;
    
    while(getline(cin, cad)){
        if(cad == "END") break;
        mySplit(cad, aut_title);
        //cout<<cad;
    }
    sort(aut_title.begin(), aut_title.end());
    int n;
    for(n=0; n<aut_title.size(); n++){
        //cout<<aut_title[i].first<<aut_title[i].second<<endl;
        positions[aut_title[n].second] = n;
    }
    vector<bool> borrowed(n+3, false);
    vector<bool> returned(n+3, false);

    while(getline(cin, cad)){
        int previous = -1;
        if(cad == "END") break;
        if(cad[0] == 'B') {
            sscanf(cad.c_str(), "BORROW \"%[^\"]\"", tem);
            cad = string(tem);
            borrowed[positions[cad]] = true;
            returned[positions[cad]] = false;
        } else if(cad[0] == 'R'){
            sscanf(cad.c_str(), "RETURN \"%[^\"]\"", tem);
            cad = string(tem);
            returned[positions[cad]] = true;
        } else if(cad[0] == 'S'){
            for(int i=0; i<n; i++){
                if(returned[i]){
                    if(previous == -1){
                        cout<<"Put \""<<aut_title[i].second<<"\" first"<<endl; 
                    } else {
                        cout<<"Put \""<<aut_title[i].second<<"\" after \""<< aut_title[previous].second<<"\""<<endl; 
                    }
                    returned[i] = false;
                    borrowed[i] = false;
                    
                    previous = i;
                } else if (not borrowed[i]){
                    previous = i;
                }
            }
            cout<<"END"<<endl;
        }
    }
    return 0;
}