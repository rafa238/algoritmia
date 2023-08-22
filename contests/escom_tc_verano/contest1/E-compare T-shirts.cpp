#include <bits/stdc++.h>
#define fastIO(); ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
typedef long long ll;
 
int main(){
    fastIO();
    int t; 
    cin >> t; 
    for(int i = 0; i < t; i++)
    {
        string a, b;
        cin >> a >> b; 
        char c1 = a[a.size()-1]; 
        char c2 = b[b.size()-1];
        if(a == b)
            cout << "=\n";
        else if(c1 == 'S' && (c2 == 'M' || c2 == 'L'))
            cout << "<\n";
        else if(c1 == 'M' && c2 == 'L')
            cout << "<\n";
        else if(c1 == 'L' && (c2 == 'S' || c2 == 'M'))
            cout << ">\n";
        else if(c1 == 'M' && c2 =='S')
            cout << ">\n"; 
        else if(c1== 'S') {
            if(a.size() > b.size())
                cout << "<\n";
            else
                cout << ">\n";
        }else if(c1== 'L') {
            if(a.size() > b.size())
                cout << ">\n";
            else
                cout << "<\n";
        }
    }
    return 0;
}