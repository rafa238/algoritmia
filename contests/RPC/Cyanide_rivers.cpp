#include<bits/stdc++.h>
using namespace std;


int main(){
    
    string s, aux; cin>>s;
    vector<int> howFar = vector<int>(s.size(), 1000000);

    int lastOne = 0;
    for(int i=0; i<s.size(); i++){
        if(s[i] == '1'){
            lastOne = i;
            howFar[i] = 0;
        } else {
            howFar[i] = min(howFar[i], i-lastOne);
        }
    }
    
    for(int i=s.size()-1; i>=0; i--){
        if(s[i] == '1'){
            lastOne = i;
            howFar[i] = 0;
        } else {
            howFar[i] = min(howFar[i], lastOne-i);
        }
    }
    int ans = INT_MIN;
    for(int i=0; i<s.size(); i++){
        cout<<howFar[i]<<" ";
        ans = max(howFar[i], ans);
    }


    cout<<ans<<endl;
    return 0;
}