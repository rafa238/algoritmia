#include <iostream>
#include<set>
#include<string.h>
#include <algorithm>

using namespace std;

int dp[4000+13];

int cortes(int n, set<int> abc){
    if(dp[n] != -1) return dp[n];
    if(n < 0){
        return 0;
    } else if (n==0){
        return 1;
    }
    int sum = 0;
    for (const int number : abc) {
        sum += cortes(n-number, abc);
        dp[n] = sum;
    }
    return sum;
}

int main()
{
    set<int> abc;
    int n,a,b,c;
    cin>> n;
    int i=0, cort=0;
    while(i<3){
        int a;
        cin >> a;
        abc.insert(a);
        if(a==n) cort--;
        i++;
    }
    memset (dp, -1 ,sizeof(dp));

    if(abc.size() == 1){
        cout<<1;
    } else {
        cort += cortes(n, abc);
        cout<< cort;
    }
    return 0;
}
/*
void 2DArrayDS(){
        const int tam = 6;
    int arr[tam][tam];
    for (int i = 0; i < tam; i++) {
        for (int j = 0; j < tam; j++) {
            cin>>arr[i][j];
        }
    }

    int relojes[4][4];
    for (int i = 0; i < tam; i++) {
        for (int j = 0; j < tam; j++) {
            if (tam-i < 3 || tam-j <3) break;
            int suma =  arr[i][j]+ arr[i][j+1]+arr[i][j+2]+ 0 + arr[i+1][j+1]+ 0
            + arr[i+2][j]+arr[i+2][j+1] + arr[i+2][j+2];
            relojes[i][j] = suma;
        }
    }
    int max = relojes[0][0];
    for (int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            //cout<<relojes[i][j];
            if(relojes[i][j] > max){
                max = relojes[i][j];
            }
        }
    }
    cout<<max;
}*/

/*
    void beatifulMatrix(){
            const int tam = 5;
    int arr[tam];
    int x,y, despx, despy, desp;
    for (int i = 0; i < tam; i++) {
        for(int j=0; j<tam; j++){
            cin>>arr[i];
            if(arr[i] == 1){
                x = j;
                y=i;
            }
        }
    }

    despx = abs(x+1-3);
    despy = abs(y+1-3);
    //cout << despx <<"ola: "<<  despy<< "coor" <<x << ": " <<y <<endl;
    desp = despx + despy;
    cout<< desp;
    }
*/

/*
void stonesOnTable(){
    int tam;
    cin>>tam;
    char pied[tam];
    for (int i=0;i<tam;i++){
        cin>>pied[i];
    }
    int cont = 0;
    for (int i=0;i<tam;i++){
        if(pied[i]==pied[i+1]) cont++;
    }
    cout<<cont;
}
*/
/*
void arrayManupulation(){
    int n, m;
    cin>> n >> m;
    //cout<<n<<m;
    int abk[m][3];
    for(int i=0; i<m; i++){
        for(int j=0; j<3; j++){
            cin>>abk[i][j];
        }
    }
    int arr[m][n]={};

    for(int i=0;i<m; i++){
        int a=abk[i][0], b=abk[i][1], c=abk[i][2];
        for(int j=0; j<n; j++){
            if(j+1>=a && j+1<=b){
                //cout<<"entro"<<a<<b;
                arr[i][j]+=c;
            }
            if(i+1<m) arr[i+1][j] = arr[i][j];
            //cout<<arr[i][j]<<" ";
        }
        //cout<<"\n";
    }
    int max=arr[0][0];
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(max < arr[i][j]) max=arr[i][j];
        }
    }
    cout<<max;
}*/

/*
void arraysDS(){
    int len;
    cin>>len;
    int arr[len];
    for(int i=0; i< len; i++){
        cin>>arr[i];
    }

    for(int i=len-1; i>=0; i--){
        cout<<arr[i];
    }
}
*/
/*
void 2DArrayDS(){
    int arr[6][6];
    for(int i=0; i<6; i++){
        for(int j=0; j<6; j++) {
            cin>>arr[i][j];
        }
    }

    int reloj[3][3] = {0,0,0,0,0,0,0,0,0};
    int relojes[4][4];
    cout<<"buenas";
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            reloj[i][j] = arr[i][j];
            cout<<arr[i][j]<<endl;
        }
    }
}*/

/*
void leftRotation(){
  int tam, cambios;
    cin>> tam >> cambios;
    int arr[tam], arre[tam];
    for(int i=0; i<tam; i++){
        cin >> arr[i];
    }

    for (int j=0; j<tam; j++){
        int pos = j - cambios;
        if( pos < 0) pos += tam;
        arre[pos] = arr[j];
    }

    for(int k=0; k<tam; k++){
        cout<< arre[k] << " ";
    }

}
*/

/*
void queueSchool(){
    int n, t;
    cin>> n >> t;
    char chil[n];
    for(int i=0; i<n; i++) {
        cin>>chil[i];
    }

    for(int j=0; j<t; j++) {
        for(int i=n-1; i>=0; i--) {
            if(chil[i]=='G' && chil[i-1]=='B'){
                chil[i] = 'B';
                chil[i-1] = 'G';
                i--;
            }
        }
    }

    for(int i=0; i<n; i++) {
        cout<<chil[i];
    }

}
*/
