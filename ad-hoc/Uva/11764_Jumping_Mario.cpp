#include<bits/stdc++.h>
using namespace std;

int main(){
    int tc, i = 0, highJ, lowJ, walls, prevWall; 
    cin>>tc;
    while(tc--){
        cin >> walls;
        highJ = lowJ = 0;
        cin>>prevWall;
        for(int i=1; i<walls; i++){
            int nxtWall; cin>>nxtWall;
            if(nxtWall > prevWall ) highJ++;
            else if(nxtWall < prevWall) lowJ++;
            prevWall = nxtWall;
        }
        
        cout<<"Case "<< ++i << ": " << highJ << " " << lowJ << endl;
    }
    return 0;
}