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
}