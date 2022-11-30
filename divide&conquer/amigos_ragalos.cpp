#include <stdio.h>

long long int c1,c2,p,q,mitad,res1,aux,res2,res3;


int check(long long int n){
    res1=n-(n/p);
    res2=n-(n/p)-(n/q)+(n/(p*q));
    res3=n-(n/q);
    res3-=res2;
    res1-=res2;
    if(res3<c2)
        res2-=c2-res3;
    if(res2<0)
        return 0;
    if(res1<c1)
        res2-=c1-res1;
    if(res2<0)
        return 0;
    return  1;
}

long long int bs(long long int ini, long long int fin){
    mitad=(ini+fin)/2;
    if(ini==fin)
        return ini;
    if(check(mitad))
        return bs(ini,mitad);
    else 
        return bs(mitad+1,fin);
}

int main(){
    scanf("%lld" "%lld" "%lld" "%lld",&c1,&c2,&p,&q);
    printf("%lld\n", bs(c1+c2, 6LL*(c1+c2)));
    return 0;
}