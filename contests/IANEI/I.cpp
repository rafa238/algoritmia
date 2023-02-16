#include <bits/stdc++.h>
using namespace std;

int main(){
    int tc; cin>>tc;
    getchar();
    while(tc--){
        stack<string> asterix;
        stack<string> underscores;
        string s;
        getline(cin, s);
        for(char elem: s){
            if(elem=='*'){
                if(asterix.empty()){
                    cout<<"<b>";
                    asterix.push("</b>");
                } else {
                    cout<<asterix.top();
                    asterix.pop();
                }
            } else if(elem == '_'){
                if(underscores.empty()){
                    cout<<"<i>";
                    underscores.push("</i>");
                } else {
                    cout<<underscores.top();
                    underscores.pop();
                }
            } else {
                cout<<elem;
            }
        }
        cout<<endl;
    }
}