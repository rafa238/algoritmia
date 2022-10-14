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