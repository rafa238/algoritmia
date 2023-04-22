#include<stdio.h>
#define INT_MAX 100000;

int graph[10005][10005];

int min(int a, int b){
    if(a<b){
        return a;
    } else {
        return b;   
    }
}

int tsp(int n, int pos, int mask){
    if(mask == (1<<n)-1){
        return graph[pos][0];
    }
    int ans = INT_MAX;
    for(int nxt=0; nxt<n; nxt++){
        if((mask & (1<<nxt)) || nxt == pos) continue;
        ans = min(graph[pos][nxt] + tsp(n, nxt, (mask | (1<<nxt))), ans);
    }
    return ans;
}

int main(){
    int tc;
    scanf("%d", &tc);
    for(int i=0; i<tc; i++){
        int n;
        scanf("%d", &n);
        for(int i=0; i<n+1; i++){
            for(int j=0; j<n+1; j++){
                if(i==j){
                    graph[i][j] = 0;
                } else {
                    scanf("%d", &graph[i][j]);
                }
            }
        }
        int ans = tsp(n+1, 0, 1); 
        printf("%d\n", ans);
    }
    return 0;
}