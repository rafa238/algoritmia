#include <bits/stdc++.h>

using namespace std;

bool isBipartite(int start, vector<vector<int>> &graph){
	vector<int> colors(graph.size(), 0);
	queue<pair<int,int>> q; //node, color

	q.push({start, 1});
	colors[start] = 1;
	while(!q.empty()){
		auto current = q.front();
		q.pop();

		for(auto child:graph[current.first]){
			if(colors[child] == current.second){
				return false;
			}
			if(colors[child] == 0){
				colors[child] = (current.second == 1)?2:1;
				q.push({child, colors[child]});
			}
		}
	}
	return true;
}

int main(){
	int n; cin >> n;
	vector<vector<int>> graph(n);

	for(int i=0; i<n; i++){
		int k,v; cin >> k;
		while(k--){
			cin >> v; v--;
			graph[i].push_back(v);
		}
	}

	cout << (isBipartite(0, graph)?"YES":"NIL") << endl;

}
