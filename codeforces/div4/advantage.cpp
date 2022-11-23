#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;


int main(){
    string trash;
    int tc; cin>>tc;
    while(tc--){
        int n1; cin>>n1;
        int maxium1, maxium2;
        vector<int> nums;
        priority_queue<int> pq;
        for(int i=0; i<n1; i++){
            int num; cin>>num;
            nums.push_back(num);
            pq.push(num);
        }
        maxium1 = pq.top();
        pq.pop();
        maxium2 = pq.top();
        pq.top();
        for(int i=0; i<n1; i++){
            int ans;
            if(nums[i] != maxium1){
                ans = nums[i] - maxium1;
                cout<<ans<<" ";
            } else {
                ans = nums[i]-maxium2;
                cout<<ans<<" ";
            }
        }
        cout<<endl;
        
    }

    return 0;
}
