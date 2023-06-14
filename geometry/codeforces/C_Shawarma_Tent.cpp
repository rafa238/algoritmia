#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, sx, sy, nx, ny;
    cin>>n>>sx>>sy;
    // n,s,e,w
    vector<int> place(4, 0);
    for(int i=0; i<n; i++){
        cin>>nx>>ny;
        if(nx>sx) {
            place[2]++;
        } 
        if(nx<sx) {
            place[3]++;
        } 
        if(ny<sy){
            place[1]++;
        } 
        if(ny>sy){
            place[0]++;
        }
    }
    int ans = INT_MIN, direction;
    for(int i=0; i<place.size(); i++){
        int num = place[i];
        if(ans < num){
            direction = i;
            ans = num;
        }
    }
    if(direction == 0){
        sy++;
    } else if(direction == 1){
        sy--;
    } else if(direction == 2){
        sx++;
    } else {
        sx--;
    }
    cout<<ans<<"\n";
    cout<<sx<<" "<<sy<<"\n";
    return 0;
}