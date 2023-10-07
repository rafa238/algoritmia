#include <bits/stdc++.h>

using namespace std;

int main(){
    int n; 
    while(cin>>n, n != 0){
        int currSum = 0, maxSum = 0;
        for(int i=0; i<n; i++){
            int num; cin >> num;
            currSum += num;
            maxSum = max(currSum, maxSum);
            if(currSum < 0){
                currSum = 0;
            }
        }

        if(maxSum <= 0){
            cout << "Losing streak.\n";
        } else {
            cout << "The maximum winning streak is "<<maxSum<<".\n";
        }
    }
    return 0;
}