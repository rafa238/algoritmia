#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;


int main(){
    string trash;
    int tc; cin>>tc;
    getchar();
    while(tc--){
        int n1; cin>>n1;
        getchar();
        string s; 
        cin>>s;
        int maxium = INT_MIN;
        for(int i=0; i<s.length(); i++){
            maxium = max((int)(s[i]-'a'), maxium);
        }
        cout<<maxium+1<<endl;
    }

    return 0;
}
