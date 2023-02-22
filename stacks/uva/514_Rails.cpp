//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=0&problem=455&mosmsg=Submission+received+with+ID+28244134
#include<bits/stdc++.h>
using namespace std;

void solve(vector<int> &target){
    stack<int> s;
    int currIndex = 0;
    for(int i=1; i<=target.size(); i++){
       s.push(i);
       while(!s.empty() && target[currIndex] == s.top()){
            s.pop();
            currIndex++;
       }
    }
    
    if(s.empty()) cout << "Yes" << endl;
    else cout << "No" << endl;
}

int main(){
    int n, elem;
    while( cin>>n , n != 0){
        while(cin>>elem, elem != 0){
            vector<int> target;
            target.push_back(elem);
            for(int i=1; i<n; i++){
                cin>>elem;
                target.push_back(elem);
            }
            solve(target);
        }
        cout << endl;
    }
    return 0;
}