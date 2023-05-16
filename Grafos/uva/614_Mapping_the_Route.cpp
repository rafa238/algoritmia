#include<bits/stdc++.h>
#define VISITED 1
#define UNVISITED 0
using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long ll;

vector<vi> roadMap;
vector<vi> visited;
vector<vii> parents;
vector<vector<string>> answer;

void reset(char &c){
    c = 'L';
}

void anotherdirection(char &c){
    if(c == 'L'){ 
        c = 'U';
    }
    else if(c== 'U') {
        c = 'R';
    }
    else if(c=='R') {
        c = 'D';
    }
    else if(c == 'D') {
        c = 'L';
    }
}

void makeMove(char &c, int &x, int &y){
    visited[x][y] = 1;
    int prevx = x, prevy = y;
    if(c == 'L'){ 
        y--;
    }
    else if(c== 'U') {
        x--;    
    }
    else if(c=='R') {
        y++;
    }
    else if(c == 'D') {
        x++;
    }
    parents[x][y] = make_pair(prevx, prevy);
}

bool canMove(int x, int y, char c, int boundx, int boundy){
    if(c == 'L') {
        return (0 <= (y-1) && roadMap[x][y-1] != 1 && roadMap[x][y-1] != 3) && !visited[x][y-1]; 
    } else if(c== 'U'){
        return (0 <= x-1 && roadMap[x-1][y] != 3 && roadMap[x-1][y] != 2) && !visited[x-1][y]; 
    } else if(c=='R') {
        return (y+1 <=  (boundy-1) && roadMap[x][y] != 1 && roadMap[x][y] != 3) && !visited[x][y+1];
    } else if(c == 'D') {
        return (x+1 <= (boundx-1) && roadMap[x][y] != 2 && roadMap[x][y] != 3) && !visited[x+1][y];
    }
    return true;
}

void makeRoute(int startx, int starty, int endx, int endy, int height, int width){
    int currx = startx, curry = starty, cont=1;
    char orientation = 'L';
    while(currx != endx || curry != endy){
        if(canMove(currx, curry, orientation, height, width)){
            //join
            makeMove(orientation, currx, curry);
            answer[currx][curry] = to_string(++cont);
            reset(orientation);
        } else {
            //couldn't join and change orientation
            anotherdirection(orientation);
            //changed all possible orientations and need to return to last cell
            if(orientation == 'L'){
                visited[currx][curry] = 1;
                cont--;
                answer[currx][curry] = "???";
                int prevX = currx;
                currx = parents[currx][curry].first;
                curry = parents[prevX][curry].second;
            }
        }
    }
}

int main(){
    int height, width, startx, starty, endx, endy; 
    int casee = 0;
    while(cin>>height>>width>>startx>>starty>>endx>>endy){
        if(casee != 0){
            puts("");
            puts("");
            puts("");
        }
        if(height==0 && width==0 && startx==0 && starty==0 && endx == 0 && endy==0 ) break;
        roadMap.clear();
        roadMap.resize(height, vi(width));
        visited.clear();
        visited.resize(height, vi(width, 0));
        parents.clear();
        parents.resize(height, vii(width, make_pair(-1, -1)));
        answer.clear();
        answer.resize(height, vector<string>(width, ""));
        for(int i=0; i<height; i++){
            for(int j=0; j<width; j++){
                cin>>roadMap[i][j];
            }
        }
        makeRoute(startx-1, starty-1, endx-1, endy-1, height, width);
        answer[startx-1][starty-1] = "1";

        //show answer
        cout<<"Maze "<<to_string(++casee)<<"\n\n";
        for(int j=0; j<width; j++){
            if(j==0) cout<<"+";
            cout<<"---+";
        }
        puts("");
        for(int i=0; i<answer.size(); i++){
            
            for(int j=0; j<answer[i].size(); j++){
                if(j == 0) cout<<"|";
                if(answer[i][j] != "???"){
                    int spaces = 3 - answer[i][j].size();
                    for(int z = 0; z<spaces; z++){
                        cout<<" ";
                    }
                }
                cout<<answer[i][j];
                if(roadMap[i][j] == 1 || roadMap[i][j] == 3 || j==width-1){
                    cout<<"|";
                } else {
                    cout<<" ";
                }
            }
            cout<<endl;
            for(int j=0; j<answer[i].size()+1 && i!=answer.size()-1; j++){
                cout<<"+";
                if(i>=0 && (roadMap[i][j] == 3 ||  roadMap[i][j] == 2)){
                    cout<<"---";
                } else if(j!=answer[i].size()) {
                    cout<<"   ";
                }
            }
            if(i!=answer.size()-1)
                cout<<endl;
        }
        for(int j=0; j<width; j++){
            if(j==0) cout<<"+";
            cout<<"---+";
        }
    }
    return 0;
}