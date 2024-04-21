#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int tc, n;
    string s;
    cin>>tc;
    while(tc--){
        cin>>n;
        cin>>s;
        map<char, int> char_bit;
        int prev = 1;
        bool flag = true;
        char_bit[s[0]] = prev;

        //cout<<char_bit[s[0]]<<" ";
        for(int i=1; i<n; i++){
            char c = s[i];
        
            if(char_bit.count(c) != 0){
                if(char_bit[c] == prev) {
                    flag = false;
                }
            } else {
                if(prev == 1){
                    char_bit[c] = 0;    
                } else {
                    char_bit[c] = 1;
                }
            }
            prev = char_bit[c];
            //cout<<c<<":"<<char_bit[c]<<" ,";
        }

        cout<<((flag) ? "YES" : "NO")<<endl;
    }
    return 0;
}