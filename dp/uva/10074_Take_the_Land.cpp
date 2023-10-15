#include <bits/stdc++.h>

using namespace std;

int maximum2DSum(vector<vector<int>> &mat, int n, int m){
    int maxSum = 0;
    for(int i=0; i<m; i++){
        for(int j = i; j<m; j++){
            int subrect = 0;
            for(int row = 0; row < n; row++){
                subrect += mat[row][j];
                if( i > 0)
                    subrect -= mat[row][i-1];
                if(subrect < 0)
                    subrect = 0;
                maxSum = max(maxSum, subrect);
            }
        }
    }
    return maxSum;
}

int main(){
    int n, m; 
    while(cin >> n >> m && n != 0 && m != 0){
        vector<vector<int>> mat(n, vector<int>(m));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                int elem; cin >> elem;
                elem = (elem == 0) ? 1 : -200;
                mat[i][j] = elem;
                if(j > 0)
                    mat[i][j] += mat[i][j-1]; 
            }
        }
        cout << maximum2DSum(mat, n, m) << "\n";
    }
    return 0;
}