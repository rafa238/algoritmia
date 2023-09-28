#include <bits/stdc++.h>

using namespace std;
int n, m;
vector<vector<char>> mat;

void expand(int i, int j, int direction){
    if(i<0 || i>=n || j < 0 || j >= m) return;
    if(mat[i][j] == '.') return;
    mat[i][j] = '.';
    if(direction == 1){
        expand(i-1, j, direction);
    } else if(direction == 2){
        expand(i, j-1, direction);
    } else if(direction == 3){
        expand(i+1, j, direction);
    } else if(direction == 4){
        expand(i, j+1, direction);
    }
}

int main(){
    cin>>n>>m;
    mat.assign(n, vector<char>(m));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>mat[i][j];
        }
    }
    bool ans = false;
    for(int i=1; i<n; i++){
        for(int j=1; j<m; j++){
            if(mat[i][j] == '*' 
            && mat[i-1][j] == '*'
            && mat[i][j-1] == '*'
            && mat[i+1][j] == '*'
            && mat[i][j+1] == '*'){
                mat[i][j] = '.';
                expand(i-1, j, 1);
                expand(i, j-1, 2);
                expand(i+1, j, 3);
                expand(i, j+1, 4);
                ans = true;
                break;
            }
        }
        if(ans) break;
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(mat[i][j] == '*'){
                ans = false;
            }
        }
    }
    cout<<(ans ? "YES" : "NO")<<"\n";
    return 0;
}