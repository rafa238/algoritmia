#include<bits/stdc++.h>
using namespace std;
int n, g, total, minimum;
vector<int> p;
vector<pair<int, int>> solutions;

void solve(int idx, int mask, int sum){
    int currScore = ((sum*100) / total);
    if( currScore >= g ) {
        solutions.push_back(make_pair(mask, currScore));
        minimum = min(__builtin_popcount(mask), minimum);
    }
    if(mask & (1<<n) || idx >= n) return;
    for(int i = idx+1; i<n; i++){
        solve(i, mask | (1<<i), sum + p[i]);
    }
}

int main(){
    cin>>n>>g;
    total = 0;
    p.resize(n);
    minimum = INT_MAX;
    for(int i=0; i<n; i++){
        cin>>p[i];
        total += p[i];
    }
    for(int i=0; i<n; i++){
        solve(i, (1<<i), p[i]);
    }
    sort(solutions.begin(), solutions.end());
    vector<pair<int, int>> ans;
    for(auto elem: solutions){
        if(__builtin_popcount(elem.first) == minimum){
            ans.push_back(elem);
        }
    }
    cout<<minimum<<" "<<ans.size()<<endl;
    for(auto elem: ans){
        cout<<elem.second<<" ";
        for(int i=0; i<n; i++){
            if(elem.first & (1<<i)){
                cout<<i+1;
                if(elem.first != (1<<i)){
                    cout<<" ";
                }
                elem.first = elem.first - (1<<i);
            }
        }
        cout<<endl;
    }
    return 0;
}