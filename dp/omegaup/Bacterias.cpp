//2576. Bacterias
//https://omegaup.com/arena/problem/mirBacterias#problems
#include<bits/stdc++.h>
using namespace std;
//matrix will stor all the optimal solution to get to an cell
int matrix[110][110], optimal[110][110];
int n, m;

int main(){
    //get data
    cin >> m >> n;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cin >> matrix[i][j];
        }
    }
    
    //set base case
    optimal[0][0] = matrix[0][0];
    for(int j=1; j<n; j++){
        optimal[0][j] = optimal[0][j-1] + matrix[0][j];
    }
    for(int j=1; j<m; j++){
        optimal[j][0] = optimal[j-1][0] + matrix[j][0];
    }

    // fill the table
    for(int i=1; i<m; i++){
        for(int j=1; j<n; j++){
            optimal[i][j] = min(optimal[i-1][j], optimal[i][j-1]) + matrix[i][j]; 
        }
    }

    //solution 
    cout<<optimal[m-1][n-1];
    return 0;
}