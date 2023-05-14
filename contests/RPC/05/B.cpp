#include<bits/stdc++.h>

using namespace std;

int main(){
    int n, k; cin>>n>>k;
    vector<pair<int, int>> bubbles;
    priority_queue<pair<int, int>> pq;
    for(int i=0; i<n; i++){
        int elem; cin>>elem;
        pq.push(make_pair(-elem, i));
    }
    int maxium = INT_MIN;
    int i=0;
    while(!pq.empty()){
        //cout<<pq.top().first<<" "<<pq.top().second<<endl;
        
            maxium = max(pq.top().second-i, maxium);
        
        pq.pop();
        i++;
    }
    float ans = (float)maxium/(float)(k-1);
    cout<<ceil(ans)<<endl;
    return 0;
}