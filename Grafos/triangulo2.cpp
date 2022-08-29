#include <bits/stdc++.h>
using namespace std;

bool hasTriangle(int me, vector<int> &grafo){
    int vueltas = 3;
    queue<int> q;
    q.push(me);
    while(vueltas--){
        int f = q.front();
        q.pop();
        //insertamos el hijo
        q.push(grafo[f]);
    }
    return me == q.front();
}

int main(){
    int N; cin>>N;
    vector<int> grafo(N+1);
    for (int i = 0; i < N; i++){
        int per; cin>>per;
        grafo[i+1]=per;
    }
    bool ans = false;
    for (int i = 1; i < N; i++){
        ans = ans || hasTriangle(i, grafo);
    }
    /*for (int i = 0; i < grafo.size(); i++){
        cout<< i << " : " <<grafo[i];
        cout<<endl;
    }*/
    cout << (ans?"YES":"NO") << endl;
    return 0;
}