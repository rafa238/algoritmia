#include <bits/stdc++.h>
using namespace std;
vector<vector<char>> grid;
vector<vector<bool>> visited;
int rows, columns, ans;
int si, sj;
string direction = "><^v";
vector<int> dx = {0, 0, -1, 1}, dy = {1, -1, 0, 0};
/*
    1: right,
    2: left,
    3: up,
    4: down
*/
void propagateSights(int i, int j, int type){
    if(i<0 || i >= rows || j<0 || j >= columns)
        return;
    if((grid[i][j] != '-' && grid[i][j] != '.') && grid[i][j] != direction[type-1]) 
        return;
    if(grid[i][j] != '>' && grid[i][j] != '<' && grid[i][j] != '^' && grid[i][j] != 'v')
        grid[i][j] = '-';
    if(type == 1){
        propagateSights(i + dx[0], j + dy[0], type);
    } else if(type == 2){
        propagateSights(i + dx[1], j + dy[1], type);
    } else if(type == 3){
        propagateSights(i + dx[2], j + dy[2], type);
    } else if(type == 4){
        propagateSights(i + dx[3], j + dy[3], type);
    }
}

void bfs(){
    queue<pair<pair<int, int>, int>> q;
    q.push({{si, sj}, 0});
    grid[si][sj] = '.';
    while(!q.empty()){
        pair<pair<int, int>, int> p = q.front();
        q.pop();
        if(p.first.first<0 || p.first.first >= rows || p.first.second<0 || p.first.second >= columns)
            continue;
        if(grid[p.first.first][p.first.second] == 'G'){
            ans = p.second;
            break;
        }
        if(visited[p.first.first][p.first.second]){
            continue;
        }
        if(grid[p.first.first][p.first.second] != '.'){
            continue;
        }
        //cout<<p.first.first<<" "<<p.first.second<<" \n";
        visited[p.first.first][p.first.second] = true;
        for(int i=0; i<4; i++){
            q.push({make_pair(p.first.first + dy[i] , p.first.second + dx[i]), p.second + 1});
        }
        
    }

} 


int main(){
    cin>>rows>>columns;
    grid.resize(rows, vector<char>(columns));
    visited.resize(rows, vector<bool>(columns, false));
    ans = -1;
    for(int i=0; i<rows; i++){
        for(int j=0; j<columns; j++){
            char c;
            cin>>c;
            if(c == 'S'){
                si = i;
                sj = j;
            }
            grid[i][j] =  c;
        }
    }
     
    for(int i=0; i<rows; i++){
        for(int j=0; j<columns; j++){
            if(grid[i][j] == 'v'){
                propagateSights(i, j, 4);
            } else if(grid[i][j] == '<'){
                propagateSights(i, j, 2);
            } else if(grid[i][j] == '>'){
                propagateSights(i, j, 1);
            } else if(grid[i][j] == '^'){
                propagateSights(i, j, 3);
            }
        }
    }

     
    /*for(int i=0; i<rows; i++){
        for(int j=0; j<columns; j++){
            cout<<grid[i][j];
        }
        cout<<"\n";
    }*/
    bfs();
    cout<<ans<<"\n";

    return 0;
}