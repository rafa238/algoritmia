#include<vector>
#include<cstdio>
using namespace std;
int main (){
    int n, tc;
    vector<vector<int>> graph;
    while(scanf ("%d %d", &n, &tc) != EOF){
        graph.assign(10e6+1, vector<int>());
        for(int i=1; i<=n; i++){
            int elem; scanf("%d", &elem);
            graph[elem].push_back(i);
        }
        for(int i=0; i<tc; i++){
            int k, v;
            scanf("%d %d", &k, &v);
            if(k-1 < graph[v].size()){
                printf("%d\n", graph[v][k-1]);
            } else {
                printf("0\n");
            }
        }
    }
    return 0;
}