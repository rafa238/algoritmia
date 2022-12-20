//https://codeforces.com/contest/1772/problem/B
#include <bits/stdc++.h>
 
using namespace std;

bool check(int m[]){
    return (m[0] < m[2] && m[1] < m[3]) && (m[0] < m[1] && m[2] < m[3]);
}

void rotate(int m[]){
    int aux1 = m[0];
    int aux2 = m[1];
    int aux3 = m[2];
    int aux4 = m[3];
    m[0] = aux3;
    m[1] = aux1; 
    m[2] = aux4;
    m[3] = aux2;
}

int main(){
    int tc;cin>>tc;
    int a, b;
    while (tc--){
        int m[4];
        bool ans = false;
        scanf("%d %d\n%d %d", &m[0], &m[1], &m[2], &m[3]);
        for(int i=0; i<4; i++){
            //printf("%d %d\n%d %d\n", m[0], m[1], m[2], m[3]);
            ans = check(m);
            if(ans) break;
            rotate(m);
        }
        cout<<((ans)?"YES":"NO")<<endl;
    }
}