#include<bits/stdc++.h>
//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=608&page=show_problem&problem=3912
using namespace std;

int main(){
    int currChannel, target, ans;
    while(cin>>currChannel>>target, currChannel != -1 && target != -1){
        if(currChannel<target){
            ans = min(target-currChannel, 100 - (target-currChannel));
        } else {
            ans = min(currChannel-target, 100 - (currChannel - target));
        }
        cout<<ans<<endl;
    }
    return 0;
}