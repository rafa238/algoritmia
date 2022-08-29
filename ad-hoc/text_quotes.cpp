#include <bits/stdc++.h>

using namespace std;

int main(){
    char text[1000];
    int cont = 1;
    while(gets(text)){
        for(int i = 0; text[i]; i ++) {
            if(text[i] == '"'){
                if(cont % 2 == 0){
                    cout<<"''";
                    cont = 1;
                } else {
                    cout<<"``";
                    cont++;
                }
            } else {
                cout<<text[i];
            }
            cout<<"\n";
        }
    }
    return 0;
}

