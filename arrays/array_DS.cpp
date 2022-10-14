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