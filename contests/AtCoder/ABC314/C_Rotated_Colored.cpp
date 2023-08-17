#include <bits/stdc++.h>

using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    int n, m;
    cin>>n>>m;
    vector<deque<char>> bucket(m+1, deque<char>());
    string s; cin>>s;
    vector<int> colors(n);
    for(int i=0; i<n; i++){
        cin>>colors[i];
        bucket[colors[i]].push_back(s[i]);
    }

    for(deque<char> &elem : bucket){
        if(elem.size() == 0) continue;
        char aux = elem.back();
        elem.pop_back();
        elem.push_front(aux);
    }

    string ans = "";
    for(int i=0; i<n; i++){
        int bucketNum = colors[i];
        char current = bucket[bucketNum].front();
        bucket[bucketNum].pop_front();
        ans.push_back(current); 
    }

    cout<<ans<<"\n";

    return 0;
}
