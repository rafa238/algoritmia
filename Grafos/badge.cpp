#include<bits/stdc++.h>

using namespace std;

int bfs(vector<vector<int>> &graph, int a, int N){
    vector<int> state(N+1, 0);
    queue<int> bfs;
    bfs.push(a);
    
    while(state[bfs.front()] != 2){
        state[bfs.front()] += 1;
        int f = bfs.front();
        bfs.pop();
        for (int i = 1; i < graph[f].size(); i++){
            bfs.push(graph[f][i]);
        }
    }
    return  bfs.front();
}

int main(){
    int N; cin>>N;
    vector<vector<int>> graph(N+1);
    for (int i = 0; i < N; i++){
        int num; cin>>num;
        graph[i+1] = {i+1, num}; 
    }

    for (int i = 0; i < N; i++){
        cout << bfs(graph, i+1, N)<<" ";
    }
    //aqui lo use para ver el grafo jsjsj
    /*for (int i = 0; i < graph.size(); i++){
        for (int j = 0; j < graph[i].size(); j++){
            cout<<graph[i][j];
        }
        cout<<endl;
    }*/

    return 0;
}