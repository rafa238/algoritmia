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