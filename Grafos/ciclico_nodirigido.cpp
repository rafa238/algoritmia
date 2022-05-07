#include <bits/stdc++.h>

using namespace std;


bool hasCycle(int me, int father, vector<bool> &visited, vector<vector<int>> &graph){
	if(visited[me]) return true;
	visited[me] = true;

	bool sol = false;
	for(auto child:graph[me]){
		if(child != father){
			sol = sol || hasCycle(child, me, visited, graph);
		}
	}

	return sol;
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

	vector<bool> visited(n, false);
	cout << (hasCycle(0, -1, visited, graph)?"YES":"NO") << endl;

}
