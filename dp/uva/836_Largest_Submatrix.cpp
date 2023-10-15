#include <bits/stdc++.h>

using namespace std;
#define inf 26*26;
int maximum2DSum(int &n, vector<vector<int>> &matrix){
    int ans = INT_MIN;
    for(int l = 0; l < n; l++){
        for(int c = l; c < n; c++){
            int currRect = 0;
            for(int row = 0; row < n; row++){
                currRect += matrix[row][c];
                if(l>0)
                    currRect -= matrix[row][l-1];
                if(currRect < 0)
                    currRect = 0;
                ans = max(ans, currRect);
            }
        }
    }
    return ans;
}

int main(){
    int tc; cin>>tc;
    getchar();
    while(tc--){
        string ln; 
        cin >> ln;
        int n = ln.size();
        vector<vector<int>> matrix(n, vector<int>(n, 0));

        for(int i=0; i<n; i++){
            if(ln[i] == '1'){
                matrix[0][i]++;
            } else {
                matrix[0][i] = -inf;
            }
            if(i > 0)
                matrix[0][i] += matrix[0][i-1];
        }
        for(int i = 1; i < n; i++){
            cin>>ln;
            for(int j = 0; j < n; j++){
                if(ln[j] == '1')
                    matrix[i][j]++;
                else {
                    matrix[i][j] = -inf;
                }
                if(j > 0)
                    matrix[i][j] += matrix[i][j-1];
            }
        }
        cout << maximum2DSum(n, matrix) << "\n";
        if(tc != 0)
            puts("");
    }
    return 0;
}