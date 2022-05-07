#include<bits/stdc++.h>

using namespace std;

void insertion_sort(vector<int> &array){
    for(int j=1; j<array.size(); j++){
        int key = array[j];
        int i=j-1;
        while(i>=0 && array[i]>key){
            array[i+1] = array[i];
            i = i-1;
        }
        array[i+1] = key;
    }
}

int main(){
    vector<int> array;
    int n;
    cout<<"Ingresa el  numero de items a ingresar al insertion sort: \n";
    cin>>n;
    while(n--){
        int i;
        cout<<"Ingresa elemento:"<<endl;
        cin>>i;
        array.push_back(i);
    }
    insertion_sort(array);
    cout<<"LISTA ORDENADA:"<<endl;
    for (int i = 0; i < array.size(); i++){
        cout<< "Elemento: " << array[i] << endl;
    }
    return 0;
}