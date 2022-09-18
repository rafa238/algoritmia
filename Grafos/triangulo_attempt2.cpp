#include<bits/stdc++.h>

using namespace std;

int main(){
    int N; cin>>N;
    vector<vector<int>> grafo(N+1);
    for (int i = 0; i < N; i++){
        int per; cin>>per;
        grafo[i+1]={i+1, per};
    }
    queue<int> bfs;
    vector<int> state(N+1, 0);
    

    return 0;
}