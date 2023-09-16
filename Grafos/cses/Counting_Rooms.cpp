#include <bits/stdc++.h>
//https://cses.fi/problemset/task/1192
using namespace std;

vector<vector<char>> grid;
int r, c;

void dfs(int i, int j){
    if(i<0 || i >= r || j < 0 || j >= c){
        return;
    }
    if(grid[i][j] == '.'){
        grid[i][j] = '#';
        dfs(i, j+1);
        dfs(i+1, j);
        dfs(i-1, j);
        dfs(i, j-1);
    }
}

int main(){
    int ans = 0;
    cin >> r >> c;
    grid.resize(r, vector<char>(c));
    for(int i = 0; i < r; i++){
        for(int j=0; j < c; j++){
            cin>>grid[i][j];
        }
    }
    for(int i = 0; i < r; i++){
        for(int j=0; j < c; j++){
            if(grid[i][j] == '.') {
                ans++;
                dfs(i, j);
            }
        }
    }
    cout << ans << "\n";
    return 0;
}