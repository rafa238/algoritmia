#include<bits/stdc++.h>
using namespace std;


int main(){
    int i, j, n;
    char elem;
    stack<char> s;
    cin>>n;
    int max = 0;
    for(int p=0; p<n; p++){
        cin>>elem;
        if(elem == 'a'){ 
            s.push(elem);
        } else {
            int cont = 0;
            while(!s.empty()){
                s.pop();
                cont++;
            }
            if(cont > 1) max += cont;
        }
    }
    int cont=0;
    while(!s.empty()){
        s.pop();
        cont++;
    }
    if(cont > 1) max += cont;
    cout<<max<<endl;
}
