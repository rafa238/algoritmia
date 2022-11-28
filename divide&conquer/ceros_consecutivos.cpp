#include <stdio.h>
typedef long long int ll;

int solve(int n){
    int casoBase[] = {2, 4, 7};
    if(n<=3){
        return casoBase[n-1];
    } else{
        return solve(n-1)+solve(n-2)+solve(n-3);
    }
}

int main(){
    int n, trash;
    trash = scanf("%d", &n);
    printf("%d", solve(n));
    return 0;
}