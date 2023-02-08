#include <bits/stdc++.h>
using namespace std;

int main(){
    int w1, h1, w2, h2;
    cin>>w1>>h1>>w2>>h2;
    int a1, a2;
    a1 = (w1+2)*(h1+1) - (w1*h1);
    a2 = ((w2+2)*(h2+1)) - (w2*h2);
    cout << a1 + a2 + abs(w1-w2) << endl;
    return 0;
}