#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, k, elem; 
    scanf("%d %d", &n, &k);
    int elems[n];
    int const num = 5e6+1;
    vector<int> freq(num);
    
    for(int i=0; i<n; i++){
        scanf("%d", &elem);
        elems[i] = elem;
    }
    int maxium = INT_MIN;
    int j=0;
    int freq2 = 0;
    pair<int, int> coord;
    for(int i=0; i<n; i++){
        elem = elems[i];
        freq[elem]++;
        if(freq[elem]==1) {
            freq2++; 
        }
        //cout<<freq[elem]<<" "<<elem<<endl;
        
        // cout<<freq2<<" : "<<elem<<" -> "<< elems[j]<<endl;
        while (freq2>k) {
            freq[elems[j]]--;
            if(freq[elems[j]] == 0) freq2--;
            j++;
        }
        //cout<<freq2<<" : "<<elem<<" -> "<< elems[j]<<endl;
        if(i-j>maxium){
            maxium = i-j;
            coord = make_pair(i, j);
        }
        

    }
    cout<<coord.second+1<<" "<<coord.first+1<<endl;
    return 0;
}