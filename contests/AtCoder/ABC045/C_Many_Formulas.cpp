#include <bits/stdc++.h>

using namespace std;
string num; 
long long ans;
void backtrack(long long left, int last){
    if(last == num.size()-1){
        //cout<<endl;
        ans += left;
        //cout<<"sumo: "<<left<<endl;
        return;
    }
    //cout<<left<<" ";
    string curr = "0";
    for(int i=last+1; i < num.size(); i++){
        curr += num[i];
        backtrack(left + stol(curr), i);
    }
    //cout<<"sumo: "<<left<<endl;
    //ans += left;
}

int main(){
    cin>>num;
    ans = 0;
    string s = "0";
    for(int i=0; i<num.size(); i++){
        s += num[i];
        backtrack(stol(s), i);
    }
    cout << ans << endl;
    return 0;
}