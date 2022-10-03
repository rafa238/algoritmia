#include<bits/stdc++.h>

using namespace std;

int bs(int target, vector<int> elements){
    int l=0, r=elements.size()-1;
    while(r-l > 1){
        int t = (r + l)/2;
        if(elements[t] < target){
            l = t+1;
            
        } else {
            r = t;
        }
    }
    if(elements[l] == target){
        return l+1;
    } else if(elements[r]==target ){
        return r;
    }

    return -1;
}

int main(){
    int N, Q; cin>>N>>Q;

    vector<int> arr(N);

    for (int i=0; i<N; i++){
        int elem; cin>>elem;
        arr[i] = elem;
    }

    while (Q--){
        int target; std::cin>>target;
        cout<<bs(target, arr)<<endl;
    }
    return 0;
}