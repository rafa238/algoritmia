#include <stdio.h>
#include <stdlib.h>

int main() {
    while(true){
        int N;
        scanf("%d", &N);
        if(N!=42){
            printf("%d\n", N);
        } else {
            exit(0);
        }
    }
}