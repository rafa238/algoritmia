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