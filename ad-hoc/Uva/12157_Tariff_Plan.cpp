#include<bits/stdc++.h>
//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=608&page=show_problem&problem=3309
using namespace std;

int main(){
    int tc, n, callDuration, mile, juice, i=0; 
    cin>>tc;
    while(tc--){
        cin>>n;
        mile = juice = 0;
        for(int i=0; i<n; i++){
            cin>>callDuration;
            mile += (callDuration / 30) * 10 + 10;
            
            juice += (callDuration / 60) * 15 + 15;;
        }
        cout<<"Case "<<++i<<": ";
        if (mile < juice){
            cout<<"Mile "<<mile;
        }else if (mile > juice){
            cout<<"Juice "<<juice;
        } else if (mile == juice){
            cout<<"Mile Juice " << mile;
        }
        cout<<endl;
    }
    return 0;
}