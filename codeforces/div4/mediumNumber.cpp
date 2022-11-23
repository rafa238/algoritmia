#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;


int main(){
    int tc; cin>>tc;
    while(tc--){
        int n1, n2, n3;
        cin>>n1>>n2>>n3;
        priority_queue<int> pq;
        pq.push(n1);
        pq.push(n2);
        pq.push(n3);
        pq.pop();
        cout<<pq.top()<<endl;
    }
    return 0;
}
