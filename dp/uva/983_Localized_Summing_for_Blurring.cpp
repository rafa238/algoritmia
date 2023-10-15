#include <bits/stdc++.h>

using namespace std;

void solve(int n, int m){
    vector<vector<int>> mat(n, vector<int>(n));
    for(int i = n - 1; i >= 0; i--){
        for(int j = 0; j<n; j++){
            cin >> mat[i][j];
            if(j>0)
                mat[i][j] += mat[i][j-1];
        }
    }

    int newShape = n-m+1;
    vector<vector<int>> ans(newShape, vector<int>(newShape));
    int totalSum = 0;

    for(int i = 0; i < newShape; i++){
        for(int j = 0; j < newShape; j++){
            int ansElem = 0;
            for(int row = i; row < i + m; row++){
                ansElem += mat[row][j+m-1];
                if(j>0)
                    ansElem -= mat[row][j-1];
            }
            ans[i][j] = ansElem;
            totalSum += ansElem;
        }
    }

    for(int i = newShape-1; i>=0; i--){
        for(int j = 0; j<newShape; j++){
            cout << ans[i][j] << "\n";
        }
    }
    cout << totalSum << "\n";
}

int main(){
    int n, m, tc = 0;
    while(cin >> n >> m){
        if(tc != 0)
            puts("");
        solve(n , m);
        tc++;
    }
    return 0;
}