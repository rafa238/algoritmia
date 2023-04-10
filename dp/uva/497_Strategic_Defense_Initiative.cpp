#include<bits/stdc++.h>
using namespace std;

vector<int> p;
vector<int> L;
vector<int> L_id;

void print_LIS(int i, vector<int> A) {                          
    if (p[i] == -1) { printf("%d\n", A[i]); return; }
    print_LIS(p[i], A);
    printf("%d\n", A[i]);
}

void solveLIS(vector<int> A){
    int n = A.size(), k=0, end=0;
    for(int i=0; i<n; i++){
        int curr = A[i];
        int pos = lower_bound(L.begin(), L.begin() + k, curr) - L.begin();
        L[pos] = curr;
        L_id[pos] = i;
        p[i] = pos ? L_id[pos-1] : -1;
        if(pos==k){
            k = pos+1;
            end = i;
        }
    }
    cout<<"Max hits: " << k << endl; 
    print_LIS(end, A);
}

int main(){
    int missile, tc;
    cin>>tc;
    getchar();
    getchar();
    string ln;
    while(tc--){
        vector<int> missiles;
        
        while(getline(cin, ln) && ln != "") {
            sscanf(ln.c_str(), "%d", &missile);
            missiles.push_back(missile);
        }
        int n = missiles.size();
        p.resize(n, -1);
        L.resize(n, 0);
        L_id.resize(n, 0);
        solveLIS(missiles);
        cout<<endl;
    }
    return 0;
}