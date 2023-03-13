//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3999
#include<bits/stdc++.h>
using namespace std;
vector<string> song = {
    "Happy", "birthday", "to", "you", 
    "Happy", "birthday", "to", "you",
    "Happy", "birthday", "to", "Rujia",
    "Happy", "birthday", "to", "you"};

int main(){
    int n; 
    cin>>n;
    vector<string> names(n);
    for(int i=0; i<n; i++){
        cin>>names[i];
    }
    bool eveyBodySang = false, songFinished = false;
    int i=0, j=0;
    while(!eveyBodySang || !songFinished){
        cout << names[i++] <<": "<<song[j++]<<endl;
        if(i==n){
            eveyBodySang = true;
            i = 0;
        }
        if(j==16){
            songFinished = true;
            j = 0;
        } else {
            songFinished = false;
        }
    }
    return 0;
}