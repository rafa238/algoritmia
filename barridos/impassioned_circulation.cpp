#include<bits/stdc++.h>
using namespace std;
/*
   Codeforces 814
*/
int main(){

    int N; cin>>N;
    string garland;
    cin>>garland;
    int Q; cin>>Q;
    while(Q--){
        int amount, cont=0, eliminadas=0;
        char color;
        cin>>amount>>color;
        int maxim=INT_MIN;
        int p1=0,p2=0;
        while(p1<garland.size()){
            if(garland[p1] != color){
                if(eliminadas == amount){
                    maxim = max(cont, maxim);
                    cont--;
                    eliminadas--;
                    while(garland[p2]==color){
                        p2++;
                        cont--;
                    } 
                    p2++;
                }
                cont++;
                eliminadas++;
                p1++;
            } else if (garland[p1] == color){
                cont++;
                p1++;
            }
        }
        maxim = max(maxim, cont);
        cout<<maxim<<endl;
    }
}

/*
20
adbaacbadbdaabacbcad
1
2 a
*/