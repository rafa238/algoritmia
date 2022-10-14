
#include<set>
#include<string.h>
#include <algorithm>
#include <iostream>
using namespace std;

int main(){
    int n, maximo=-10000, l;
    cin>>n;
    int arr[n];
    for (int j = 0; j < n; j++){
        cin>>l;
        for(int i=0; i<l;i++){
            int num;
            cin>>num;
            if(num>maximo)maximo=num;
        }
        arr[j]=maximo;
        maximo=-1000;
    }
    for(int i=0;i<n;i++){
        cout<<"Case "<<i+1<<": "<<arr[i]<<"\n";
    }
    return 0;
}
/*
*/

/*
   
*/

/*

*/
/*
*/

/*

*/
/*
*/

/*

*/

/*

*/


