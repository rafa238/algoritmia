#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int n; cin>>n;
    ll sum = 0, count = 0;
    priority_queue<ll> pq;
    for(int i=0; i<n; i++){
        ll potion; cin>>potion;
        sum += potion;
        count++;
        if(potion < 0) pq.push(-potion);
        if(sum < 0){
            count--;
            sum += pq.top();
            pq.pop();
        }
    }
    cout<<count<<"\n";
    return 0;
}