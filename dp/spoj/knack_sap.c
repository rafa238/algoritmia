#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
int max(int a, int b){
    return (a > b) ? a : b;
}
 
int mochila(int M, int wt[], int val[], int n){
    int i,j,K[n + 1][M + 1];
    for (i = 0; i <= n; i++){
        for (j = 0; j <= M; j++){
            if (i == 0 || j == 0)
                K[i][j] = 0;
            else if (wt[i - 1] <= j)
                K[i][j] = max(val[i - 1]+ K[i - 1][j - wt[i - 1]],K[i - 1][j]);
            else
                K[i][j] = K[i - 1][j];
        }
    }
    return K[n][M];
}
 
int main(){
    int * val,*wt,s,n,i;
    scanf("%d" "%d", &s, &n);
    val = malloc(n*sizeof(int));
    wt = malloc(n*sizeof(int));
    for (i = 0; i < n; i++){
        scanf("%d" "%d", (wt+i),(val+i));
    }
    printf("%d", mochila(s, wt, val, n));
    return 0;
}
