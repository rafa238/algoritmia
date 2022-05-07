#include <bits/stdc++.h>

using namespace std;


bool hasCycle(int me, vector<int> &state, vector<vector<int>> &graph, pair<int, int> parent, int &counter){
	cout<<"me: "<<me <<" parent: "<<parent.first << " : " << parent.second<<endl;
	if(me == parent.second) counter++;
	if(state[me] == 1) { 
		return true;
	}
	if(state[me] == 2) return false;
	state[me] = 1;

	bool sol = false;
	for(int i=0; i<graph[me].size(); i++){
		sol = sol || hasCycle(graph[me][i], state, graph, pair<int, int>(me, parent.first), counter);
	}
	state[me] = 2;

	return sol;
}

int main(){
	int n, m; 
	cin >> n >> m;
	vector<vector<int>> graph(m+1);
	map<int, vector<int>> graphO;
	for(int i=0; i<m; i++){
		int k,v; 
		cin >> k >> v;
		//cout<<k<<v;
		graph[k].push_back(v);
	}

	/*for(int i=0; i<graph.size(); i++){
		for(int j=0; j<graph[i].size(); j++){
			cout<<graph[i][j];
		}
		cout<<endl;
	}*/
	int  counter = 0;
	vector<int> state(m+1, 0);
	bool ans = false;
	for(int i=1; i<graph.size(); i++){
		if(state[i] == 0) ans = ans || hasCycle(i, state, graph, pair<int, int>(0, 0), counter);
	}
	bool ans2 = ans && counter<2;
	cout << counter;
	cout << (ans2?"YES":"NO") << endl;
}