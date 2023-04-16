#include<bits/stdc++.h>
//https://codeforces.com/problemset/problem/388/C
using namespace std;

int main(){
    int n, si, c;
    int ciel, jiro;
    ciel = jiro = 0;
    cin>>n;
    priority_queue<int> remainings;
    for(int i=0; i<n; i++){
        cin>>si;
        int remaining = 0, half = si/2;
        if(si%2 != 0){
            remaining = 1;
        }
        for(int j=0; j<half; j++){
            cin>>c;
            ciel += c;
        }
        for(int j=0; j<remaining; j++){
            cin>>c;
            remainings.push(c);
        }
        for(int j=0; j<half; j++){
            cin>>c;
            jiro += c;
        }
    }
    bool switsh = true;
    while(!remainings.empty()){
        if(switsh){
            ciel += remainings.top();
        } else {
            jiro += remainings.top();
        }
        switsh = !switsh;
        remainings.pop();
    }
    cout<<ciel<<" "<<jiro<<endl;
}