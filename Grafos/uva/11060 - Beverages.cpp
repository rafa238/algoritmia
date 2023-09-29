#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> graph;
vector<int> result, visited;

void topo_sort(){
    vector<int> in_degree(graph.size(), 0);
    for(auto vec : graph){
        for(auto elem : vec){
            in_degree[elem]++;
        }
    }

    priority_queue<int, vector<int>, greater<int>> q;
    for (int i = 0; i < graph.size(); i++)
        if (in_degree[i] == 0)
            q.push(i);

    while (!q.empty()) {
        int u = q.top();
        q.pop();
        result.push_back(u);
        
        for (auto v : graph[u])
            if (--in_degree[v] == 0)
                q.push(v);
 
    }
}


int main(){
    int tc = 0;
    int drinks;
    while(cin>>drinks){
        int drink_cont = 0;
        unordered_map<string, int> m;
        unordered_map<int, string> n_m;
        graph.assign(drinks, vector<int>());
        result.clear();
        visited.assign(drinks, 0);

        for(int i=0; i<drinks; i++){
            string drink_name;
            cin>>drink_name;
            m[drink_name] = drink_cont;
            n_m[drink_cont] = drink_name;
            drink_cont++;
        }

        int e; cin>>e;
        for(int i=0; i<e; i++){
            string u, v;
            cin>>u>>v;
            graph[m[u]].push_back(m[v]);
        }

        topo_sort();
        cout<<"Case #" << ++tc << ": Dilbert should drink beverages in this order: ";
        for(auto elem : result){
            cout << n_m[elem];
            if(elem != result.back()){
                cout << " ";
            }
        }
        cout<<".\n";
        puts("");
    }
    return 0;
}