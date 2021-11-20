#include <cmath>
#include <iostream>

using namespace std;

int main()
{
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
