#include<bits/stdc++.h>

using namespace std;
int H, W;

void printMatrix(vector<vector<char>> &matrix){
    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
}

void shif_left(vector<vector<char>> &matrix){
    vector<int> column(H);
    for(int i=0; i<H; i++){
        column[i] = matrix[i][0];
    }
    for(int i=0; i<H; i++){
        for(int j=0; j<W-1; j++){
            matrix[i][j] = matrix[i][j+1];
        }
    }
    for(int i=0; i<H; i++){
        matrix[i][W-1] = column[i];
    }
}

void shif_down(vector<vector<char>> &matrix){
    vector<int> row(W);
    for(int i=0; i<W; i++){
        row[i] = matrix[H-1][i];
    }
    for(int i=H-1; i>0; i--){
        for(int j=0; j<W; j++){
            matrix[i][j] = matrix[i-1][j];
        }
    }
    for(int i=0; i<W; i++){
        matrix[0][i] = row[i];
    }
}

int main(){
    cin>>H>>W;
    vector<vector<char>> matrix(H, vector<char>(W)), matrixB(H, vector<char>(W));
    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            cin>>matrix[i][j];
        }
    }
    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            cin>>matrixB[i][j];
        }
    }
    bool ans = (matrix == matrixB) ? true : false;
    for(int i=0; i<H; i++){
        shif_down(matrix);
        for(int j=0; j<W; j++){
            if(matrix == matrixB) ans = true; 
            shif_left(matrix);
        }
    }
    
    cout<<((ans)?"Yes":"No")<<endl;

    return 0;
}