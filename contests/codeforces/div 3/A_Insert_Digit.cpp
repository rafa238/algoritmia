#include<bits/stdc++.h>
using namespace std;

int main(){
    int tc;
    cin>>tc;
    while(tc--){
        string str;
        int n, d;
        cin>>n>>d>>str;
        bool flag = true;
        for(int i=0; i<n;i++){
            char elem = str[i];
            int curr = elem - '0';
            //cout<<curr<<" ";
            if(curr<d && flag == true){
                cout<<d;
                flag = false;
            }
            cout<<curr;
        }
        if(flag) cout<<d;
        cout<<endl;
    }
    return 0;
}