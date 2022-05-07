#include <bits/stdc++.h>
//<>
using namespace std;

int main(){
    int q; cin>>q;
    while(q--){
        int k, n, m;
        cin>> k >> n >> m;
        vector<int> mono(n);
        vector<int> poli(m);
        //cout<<k<<n<<m;
        for(int i=0; i<n; i++){
            cin>>mono[i];
        }
        for(int j=0; j<m; j++){
            cin>>poli[j];
        }
        int i=0, j=0;
        vector<int> res;
        bool tieneSol = true;
        while(i != n || j != m){
            if(i !=n && mono[i] == 0){
                k++;
                i++;
                res.push_back(0);
            } else if (j != m && poli[j] == 0){
                k++;
                res.push_back(0);
                j++;
            } else if (i != n && mono[i] <= k){
                res.push_back(mono[i]);
                i++;
            } else if(j != m && poli[j] <= k){
                res.push_back(poli[j]);
                j++;
            } else {
                cout<<-1;
                tieneSol = false;
                break;
            }
        }
        if(tieneSol){    
            for(int j=0; j<res.size(); j++){
                cout<<res[j]<<" ";
            }
        }
        cout<<""<<endl;
    }
    return 0;
}