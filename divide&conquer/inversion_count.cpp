#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;


ll vencer(ll arr[], ll temp[], ll l, ll m, ll r){
    ll i, j, k;
    ll inv_count = 0;
 
    i = l;
    j = m;
    k = l;
    while ((i <= m - 1) && (j <= r)) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        }
        else {
            temp[k++] = arr[j++];
 
            inv_count = inv_count + (m - i);
        }
    }
 

    while (i <= m - 1)
        temp[k++] = arr[i++];
 

    while (j <= r)
        temp[k++] = arr[j++];

    for (i = l; i <= r; i++)
        arr[i] = temp[i];
 
    return inv_count;
}

ll divide(ll arr[], ll temp[], ll l, ll r){
    ll n = 0;
    ll m;
    if (l < r) {
        m = (r + l) / 2;

        n += divide(arr, temp, l, m);
        n += divide(arr, temp, m + 1, r);
 
        n += vencer(arr, temp, l, m + 1, r);
    }
    return n;
}

ll solve(ll arr[], ll n){
    ll temp[n];
    return divide(arr, temp, 0, n-1);
}

int main(){
    ll tc, n;
    scanf("%lld", &tc);
    while(tc--){
        scanf("%lld", &n);
        ll A[n];
        for(ll i = 0; i < n; i++){
            scanf("%lld", &A[i]);
        }
        ll ans = solve(A, n);
        printf("%lld\n", ans);
    }
    return 0;
}