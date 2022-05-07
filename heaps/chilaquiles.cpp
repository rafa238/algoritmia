#include<bits/stdc++.h>

using namespace std;

int main(){
    int N; cin >> N;
    set<int> reviews;
    priority_queue<int> maxHeap;

    for (int i=0; i<N; i++){
        int n; cin>>n;
        if(n==1){
            int review; cin>>review;
            if(reviews.find(review) == reviews.end()){
                maxHeap.push(review);
                reviews.insert(review);
            }
        } else {
            int num_reviews = floor(reviews.size()/3);
            if(!num_reviews){
                cout<<"No reviews yet"<<endl;
                continue;
            }
            vector<int> popeados;
            for (int i = 0; i < num_reviews-1; i++){
                //cout<<maxHeap.top()<<endl;
                popeados.push_back(maxHeap.top());
                maxHeap.pop();
            }
            cout<<maxHeap.top()<<endl;
            for (int i = 0; i < popeados.size(); i++){
                maxHeap.push(popeados[i]);
            }
        }
    }
    return 0;
}