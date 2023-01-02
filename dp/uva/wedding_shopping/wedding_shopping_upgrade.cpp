//uva judge- problem 11450- Wedding Shopping
#include <bits/stdc++.h>
using namespace std;

int g, money, k, TC, M, C;
int price[30][30]; // g <= 20, model <= 20
/*
* Debido a la naturaleza de la solucion solo utilizamos la columna g y g-1 cuando llenamos la dp
* por lo tanto switchearemos entre las 2 filas de la dp para llenar la ultima fila que contiene la
* solucion.
*/
bool reachable[2][210]; // g <= 20, money <= 200

void swap(int &a, int &b){
    int aux = a;
    a = b;
    b = aux;
}

int main(){
    scanf("%d", &TC);
    while(TC--){
        scanf("%d %d", &M, &C);
        for(g=0; g < C; g++){
            scanf("%d", &price[g][0]); // guardar el numero de modelos
            for(k=1; k <= price[g][0]; k++){
                scanf("%d", &price[g][k]);
            }
        }

        memset(reachable, false, sizeof reachable);
        //inicializar casos base
        for(k = 1; k <= price[0][0]; k++){
            if(M - price[0][k] >= 0){
                reachable[0][M - price[0][k]] = true;
            }
        }
        int actual = 1, prev = 0;
        for(g = 1; g < C; g++){ // itera sobre las prendas
            for(money = 0; money < M; money++){ // itera sobre el dinero
                if(reachable[prev][money]){ // si se encuentra dinero disponible
                    for(k=1; k <= price[g][0]; k++){ // entonces iteramos sobre las prendas de para comprar 
                        if(money - price[g][k] >= 0){
                            reachable[actual][money-price[g][k]] = true;
                        }
                    }
                }
            }
            swap(actual, prev);
        }
        for(money = 0; money <= M & !reachable[C-1][money]; money++);
        if(money == M+1) printf("No solution\n");
        else printf("%d\n", M-money);
    }
    return 0;
}