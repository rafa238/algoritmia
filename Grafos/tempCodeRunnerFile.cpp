#include<bits/stdc++.h>
using namespace std;

bool hasCycle(int me, vector<vector<int>> &grafo, vector<int> &state, int parent){
    if(state[me] == 1) return true;
	if(state[me] == 2) return false;
	state[me] = 1;
    
    bool ans = false;
    for(int i=1; i<grafo[me].size(); i++){
        int child = grafo[me][i];
        //cout<<child;
        if(child == parent) continue;
        ans = ans || hasCycle(child, grafo, state, me);
    }
    state[me] = 2;
    return ans;
}


int main(){
    int N; cin>>N;
    vector<vector<int>> grafo(N+1);
    for (int i = 0; i < N; i++){
        int per; cin>>per;
        grafo[i+1]={i+1, per};
    }
    vector<int> state(N+1, 0);
    bool ans = false;
    for (int i = 0; i < N; i++){
        ans = ans || hasCycle(i+1, grafo, state, 0);
    }
    /*for (int i = 0; i < grafo.size(); i++){
        for (int j = 0; j < grafo[i].size(); j++){
            cout<<grafo[i][j];
        }
        cout<<endl;
    }*/
    cout << (ans?"YES":"NO") << endl;
    return 0;
}