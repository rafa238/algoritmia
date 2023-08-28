#include <bits/stdc++.h>

using namespace std;

int main(){
    int n; cin >> n;
    int rows = n, columns = 2*n-1;
    vector<vector<int>> matrix(rows, vector<int>(columns, 0));
    matrix[0][n-1] = 1;

    for(int i=1; i<rows; i++){
        for(int j=0; j<columns; j++){
            int prev = 0, next = 0;
            if(j > 0) prev = matrix[i-1][j-1];
            if(j < columns-1) next = matrix[i-1][j+1];
            matrix[i][j] = prev ^ next;
        }
    }

    for(int i=0; i<rows; i++){
        for(int j=0; j<columns; j++){
            cout << (( matrix[i][j] == 0 ) ? "." : "*");
        }
        cout<<"\n";
    }



    return 0;
}