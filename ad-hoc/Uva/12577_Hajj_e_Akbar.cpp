#include <bits/stdc++.h>
//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=607&page=show_problem&problem=4022
using namespace std;

int main(){
    string pilgrimage;
    int i = 0; 
    while(cin>>pilgrimage, pilgrimage != "*"){
        cout<<"Case "<<++i<<": "<<((pilgrimage == "Hajj") ? "Hajj-e-Akbar" : "Hajj-e-Asghar")<<endl;
    }
    
    return 0;
}
