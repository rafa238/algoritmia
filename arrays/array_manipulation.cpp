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
}