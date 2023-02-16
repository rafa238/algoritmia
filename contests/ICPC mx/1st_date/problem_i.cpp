#include<bits/stdc++.h>
using namespace std;


int main(){
    int s; cin>>s;
    string cad = to_string(s);
    int contador=0;
    
    for(int i=0; i<cad.size(); i++){
        char car = cad[i];
        int num = (int)car -'0';
        if(num == 0) continue;
        if(s % num == 0) contador++;
    }
    cout<<contador<<endl;
    return 0;
}
