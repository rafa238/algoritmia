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