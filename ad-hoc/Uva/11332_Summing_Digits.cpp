#include<bits/stdc++.h>
//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=608&page=show_problem&problem=1904
using namespace std;
typedef long long ll;

ll solve(ll n){
    if (n <= 9) return n;
    ll sum = 0;
    while( n != 0){
        sum += (n%10);
        n /= 10;
    }
    return solve(sum);
}

int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0);

    ll n;
    while(cin>>n, n != 0){
        cout<<solve(n)<<endl;
    }
    return 0;
}