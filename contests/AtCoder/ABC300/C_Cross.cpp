#include<bits/stdc++.h>

using namespace std;
vector<int> answer;
vector<vector<char>> matrix;
int H, W;

int dx[4] = {1, 1, -1, -1};
int dy[4] = {-1, 1, 1, -1};

int dfs(int x, int y){
    int cont = 1;
    matrix[x][y] = '.';
    for(int i=0; i<4; i++){
        int despx = x + dx[i];
        int despy = y + dy[i];
        
        if(despx < 0 || despx >= H || despy < 0 || despy >= W) continue;
        if(matrix[despx][despy] != '#') continue;
        //cout<<despx<<" "<<despy<<" -> ";
        cont += dfs(despx, despy);
    }
    return cont;
}

int main(){
    cin>>H>>W;
    matrix.resize(H, vector<char>(W));
    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            cin>>matrix[i][j];
        }
    }
    int n = min(H, W);
    answer.resize(n, 0);
    
    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            if(matrix[i][j] == '#'){
                int crossSize = dfs(i, j);
                answer[((crossSize-1)/4)-1]++;
            }
        }
    }
    for(auto elem : answer ){
        cout<<elem<<" ";
    }
    return 0;
}