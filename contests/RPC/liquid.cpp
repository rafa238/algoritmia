#include <bits/stdc++.h>
using namespace std;
#define fast_io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long double ld;

int main(){
    double n, elem;
    cin>>n;
    double sum = 0;
    for(int i=0;i < n; i++){
        cin>>elem;
        sum += pow(elem, 3);
    }
    double ans = (double)pow(sum, 1/3);
    printf("%0.8lf", ans);
    return 0;
}