#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int gcd(int a, int b, int& x, int& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

bool find_any_solution(int a, int b, int c, int &x0, int &y0, int &g) {
    g = gcd(abs(a), abs(b), x0, y0);
    if (c % g) {
        return false;
    }

    x0 *= c / g;
    y0 *= c / g;
    if (a < 0) x0 = -x0;
    if (b < 0) y0 = -y0;
    return true;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int a, b, c;
    int x0, y0, g;
    cin>>a>>b>>c;
    bool ans = find_any_solution(a,b,c,x0,y0,g);
    cout<<x0<<y0;
    if(ans && (y0 > 0 && x0 > 0)) cout<<"Yes";
    else cout<<"No";
    cout<<"\n";
    return 0;
}