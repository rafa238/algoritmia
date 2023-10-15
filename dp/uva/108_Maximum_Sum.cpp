#include <bits/stdc++.h>

using namespace std;

int main(){
    int n; cin>>n;
    vector<vector<int>> matrix(n, vector<int>(n));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>matrix[i][j];
            if(j>0)
                matrix[i][j] += matrix[i][j-1];
        }
    }

    int currSubrect, ans = INT_MIN;

    for(int l = 0; l < n; l++){
        for(int c = l; c < n; c++){
            currSubrect = 0;
            for(int row = 0; row < n; row++){
                currSubrect += matrix[row][c];
                if(l > 0) 
                    currSubrect -= matrix[row][l-1];
                if(currSubrect < 0)
                    currSubrect = 0;
                ans = max(ans, currSubrect);
            }
        }
    }
    cout << ans << "\n";
    return 0;
}