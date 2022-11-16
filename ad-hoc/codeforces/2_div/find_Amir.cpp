#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie();
    int n; cin>>n;
    int cont=0;
    for(int i=1, j=1; i<n-1; i+=3){
        j=i+1;
        cont += (i+j)%(n+1);
        cout<<cont<<" ";
    }
    cout<<cont;
    cin.clear();
    cin.ignore();
    //cin.get();

    return 0;
}