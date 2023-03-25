#include <bits/stdc++.h>
//https://practice.geeksforgeeks.org/problems/path-in-matrix3805/1
using namespace std;

class Solution{
public:
    int maximumPath(int n, vector<vector<int>> matrix1){
        vector<vector<int>> matrix = matrix1;
        for(int i=1; i<n; i++){
            for(int j=0; j<n; j++){
               if(j==0){
                    matrix[i][j] = max(
                        matrix1[i][j] + matrix[i-1][j],
                        matrix[i][j]);
                    matrix[i][j] = max(
                        matrix1[i][j] + matrix[i-1][j+1],
                        matrix[i][j]);
               } else if(j==matrix[i].size()-1){
                    matrix[i][j] = max(
                        matrix1[i][j] + matrix[i-1][j-1],
                        matrix[i][j]
                    );
                    matrix[i][j] = max(
                        matrix1[i][j] +  matrix[i-1][j],
                        matrix[i][j]
                    );
               } else {
                    matrix[i][j] = max(
                        matrix1[i][j] + matrix[i-1][j-1],
                        matrix[i][j]
                    );
                    matrix[i][j] = max(
                        matrix1[i][j] +  matrix[i-1][j],
                        matrix[i][j]
                    );
                    matrix[i][j] = max(
                        matrix1[i][j] + matrix[i-1][j+1],
                        matrix[i][j]
                    );
               }
            }
        }
        int ans = INT_MIN;
        for(int i=0; i<matrix1.size(); i++){
            for(int j=0; j<matrix1[i].size(); j++){
                ans = max(ans, matrix[i][j]); 
                //cout<<matrix[i][j]<<" ";
                
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){

    int N;
    cin>>N;
    vector<vector<int>> Matrix(N, vector<int>(N, 0));
    for(int i = 0;i < N*N;i++)
        cin>>Matrix[(i/N)][i%N];
    
    Solution ob;
    cout<<ob.maximumPath(N, Matrix)<<"\n";

    return 0;
}
// } Driver Code Ends