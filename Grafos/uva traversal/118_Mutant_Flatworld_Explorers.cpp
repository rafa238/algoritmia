#include<bits/stdc++.h>
#define VISITED 1
#define UNVISITED 0
using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long ll;

bool checkPosition(int x, int y, int boundx, int boundy){
    return (0 <= x && x <= boundx && 0 <= y && y <= boundy);
}

void makeMove(int &ix, int &iy, char &currD, char c){
    if(c == 'L'){
        if(currD == 'E'){
            currD = 'N';
        } else if(currD == 'S'){
            currD = 'E';
        } else if(currD == 'W'){
            currD = 'S';
        } else if(currD == 'N'){
            currD = 'W';
        }
    } else if(c == 'R'){
        if(currD == 'E'){
            currD = 'S';
        } else if(currD == 'S'){
            currD = 'W';
        } else if(currD == 'W'){
            currD = 'N';
        } else if(currD == 'N'){
            currD = 'E';
        }
    } else if(c == 'F'){
        if(currD == 'E'){
            ix++;
        } else if(currD == 'S'){
            iy--;
        } else if(currD == 'W'){
            ix--;
        } else if(currD == 'N'){
            iy++;
        }
    }
}

int main(){
    int upperx, uppery, ix, iy;
    string D;
    char currD;
    cin>>upperx>>uppery;
    vector<vi> prev(upperx+1, vi(uppery+1, 0));
    while(scanf("%d %d %c", &ix, &iy, &currD) == 3) {
        cin>>D;
        bool flag = false;
        for(auto c : D){
            makeMove(ix, iy, currD, c);
            if(!checkPosition(ix, iy, upperx, uppery)){
                if(ix<0) ix++;
                else if(ix>upperx)ix--;
                if(iy<0) iy++;
                else if(iy>uppery)iy--;
                if(prev[ix][iy] == 1){
                    continue;
                } else {
                    flag = true;
                    prev[ix][iy] = 1;
                    break;
                }
            }
        }
        cout<<ix<<" "<<iy<<" "<<currD;
        if(flag){
            cout<<" LOST";
        }
        cout<<"\n";
    }
    return 0;
}