#include<bits/stdc++.h>
using namespace std;

int main(){
    while(true){
        int start, first, second, third, ans = 0;
        cin>> start >> first >> second >> third;
        ans += 720; //first we make two full turns
        if(!start && !first && !second && !third){
            break;
        }
        if(start > first){
            ans += 9 * (start - first);
        } else {
            ans += 9 * (40 - first + start);
        }
        ans += 360;
        if(second > first){
            ans += 9 * (second - first);
        } else {
            ans += 9 * (40 - first + second);
        }
        if(third > second){
            ans += 9 * (40 - third + second);
        } else {
            ans += 9 * (second - third);
        }
        cout<<ans<<endl;
    }
}