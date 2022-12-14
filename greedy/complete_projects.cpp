#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    
    int n, r; cin>>n>>r;
    vector<pair<int, int>> projects;
    for(int i=0; i<n; i++){
        int a, b; cin>>a>>b;
        projects.push_back(make_pair(a, b));
    }
    sort(projects.begin(), projects.end());
    priority_queue<pair<int, int>> q; 
    for(auto elem: projects){
        if(elem.first <= r){
            pair<int, int> npair = make_pair(elem.second, elem.first);
            q.push(npair);
        }
        
        //cout<<elem.first<<" "<<elem.second<<endl;
    }
    return 0;
}
/*
5 4
5 2
5 0
5 -3
2 1
4 -2
*/