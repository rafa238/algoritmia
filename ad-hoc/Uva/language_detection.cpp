//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=607&page=show_problem&problem=3402
#include<bits/stdc++.h>
using namespace std;

int main(){
    string hello;
    int i=0;
    while(cin>>hello, hello != "#"){
        cout<<"Case "<<++i<<": ";
        if(hello == "HELLO"){
            cout<<"ENGLISH";
        } else if(hello == "HOLA"){
            cout<<"SPANISH";
        } else if(hello == "HALLO"){
            cout<<"GERMAN";
        } else if(hello == "BONJOUR"){
            cout<<"FRENCH";
        } else if(hello == "CIAO"){
            cout<<"ITALIAN";
        } else if(hello == "ZDRAVSTVUJTE"){
            cout<<"RUSSIAN";
        } else {
            cout<<"UNKNOWN";
        }
        cout<<endl;
    }
    return 0;
}