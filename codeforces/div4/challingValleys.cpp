#include <bits/stdc++.h>
using namespace std;

int main(){
    int tc; cin>>tc;
    while(tc--){
        int n; cin>>n;
        vector<int> v;
        for(int i=0; i<n; i++){
            int num; cin>>num;
            v.push_back(num);
        }
        if(n == 1 || n==2){
            if(n==1 || (v[0]==v[1])) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
            continue;
        }
        bool flag=false;
        for(int r=2, l=0, c=1; r<v.size(); l++, c++, r++){
            if((v[l] >= v[c] && v[c] <= v[r]) && v[l]==v[l] ){
                cout<<l<<c<<r<<" ";
                flag = true;
            }
        }
        cout<<((flag)?"YES":"NO")<<endl;
    }
    return 0;
}
