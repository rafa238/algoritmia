#include <limits.h>
#include <stdio.h>
typedef long long int ll;

ll max(ll a, ll b) { return (a > b) ? a : b; }
ll max2(ll a, ll b, ll c) { return max(max(a, b), c); }

ll crossum(ll A[], ll l, ll m, ll r){
    ll suma;

    //COMENZAMOS CON LA CROSS SUM

    //suma izquierda
    ll sumaIzquierda = INT_MIN;
    suma = 0;
    for (int i=m; i>=l; i--){
        suma += A[i];
        if(suma>sumaIzquierda){
            sumaIzquierda = suma;
        } 
    }
    //sumaderecha
    ll sumaDerecha = INT_MIN;
    suma = 0;
    for (int i=m; i<=r; i++){
        suma += A[i];
        if(suma>sumaDerecha){
            sumaDerecha = suma;
        } 
    }

    //retorna suma total
    return max2(sumaIzquierda + sumaDerecha - A[m], sumaIzquierda, sumaDerecha);;
}

ll maxSub(ll A[], ll l, ll r){
    if (l > r)
        return INT_MIN;
    if(l == r){
        return A[l];
    }
    ll m = (l + r)/2;
    
    return max2(maxSub(A, l, m-1), maxSub(A, m+1, r), crossum(A, l, m, r));
}

int main(){
    ll n, elem, trash;
    trash = scanf("%lld", &n);
    ll A[n];
    for (ll i=0; i<n; i++){
      trash = scanf("%lld", &A[i]);
    }
    ll ans = maxSub(A,  0, n-1);
    printf("%lld", ans);
    return 0;
}