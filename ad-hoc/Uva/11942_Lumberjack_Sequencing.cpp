#include<bits/stdc++.h>
//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3093
using namespace std;

int main(){
    int tc; cin>>tc;
    int count;
    cout<<"Lumberjacks:"<<endl;
    while(tc--){
        vector<int> beards(10);
        count = 0;

        for(int j=0; j<10; j++){
            cin>>beards[j];
        }

        for(int j=0; j<9; j++){
            if(beards[j] > beards[j+1]){
                count++;
            } else if(beards[j] < beards[j+1]){
                count--;
            }
        }
        count = abs(count);
        cout<< ((count == 9) ? "Ordered" : "Unordered") <<endl;
    }
    return 0;
}