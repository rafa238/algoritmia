/* 
* 5176. Divide and conquer 1
* https://omegaup.com/arena/problem/Divide-and-conquer-1
*/ 
#include <stdio.h>
#include <stdlib.h>
#define MAX(i, j) (((i) > (j)) ? (i) : (j))
#define MAX2(i,j,k) MAX(MAX(i,j), MAX(j, k))

int maxSub(int A[], int ini, int fin){
    if(ini == fin){
        return A[fin];
    }
    int sumaDerecha = 0, sumaIzquierda = 0, sumaCentral=0, suma;
    int mitad = (ini + fin)/2;
    int izquierda = maxSub(A, ini, mitad);
    int derecha = maxSub(A, mitad+1, fin);
    
    sumaIzquierda = A[mitad];
    suma = 0;
    for (int i=mitad; i>=ini; i--){
        suma += A[i];
        if(suma>sumaIzquierda){
            sumaIzquierda = suma;
        } 
    }

    sumaDerecha = A[mitad + 1];
    suma = 0;
    for (int i=mitad+1; i<=fin; i++){
        suma += A[i];
        if(suma>sumaDerecha){
            sumaDerecha = suma;
        } 
    }
    
    sumaCentral = sumaIzquierda + sumaDerecha;
    return MAX2(sumaIzquierda, sumaCentral, sumaDerecha);
}

int main(){
    int n;
    scanf("%d", &n);
    int A[n];
    for (int i=0; i<n; i++){
        scanf("%d", &A[i]);
    }
    int ans = maxSub(A,  0, n-1);
    printf("%d ", ans);
    return 1;
}
