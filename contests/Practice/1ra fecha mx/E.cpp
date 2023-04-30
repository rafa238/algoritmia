#include<bits/stdc++.h>
using namespace std;
//pares elemento, frecuencia
vector<pair<int, int>> p;
int n, m;
int main(){
    
    cin>>n>>m;
    int minimum = INT_MAX, pivot;
    int prev = -1000;
    for(int i=0; i<n; i++){
        int employee;
        cin>>employee;
        if(employee == prev){
            p[p.size()-1].second++;      
        } else {
            p.push_back(make_pair(employee, 1));
        }
        if(employee <= minimum && employee != 0){
            minimum = employee;
            pivot = i;
        }
        prev = employee;
    }
    //cambiamos los minimos por 1
    for(int i=0; i<n; i++){
        if(p[i].first == minimum){
            p[i].first = 1;
        }
    }
    /*for(auto elem : p){
        cout<<elem.first<<" "<<elem.second<<endl;
    }*/
    //primera iteracion
    for(int i=pivot+1; i!=pivot; i++){
        if(i == n) i = 0;
        int sig = (i+1)%n, prev = (i-1 >= 0) ? i-1 : n-1;
        //int mini= min(p[prev].first, p[sig].first);
        if(p[i].first > p[sig].first && p[i].first > p[prev].first){
            p[i].first = max(p[sig].first, p[prev].first) + 1;
        } else if(p[prev].first > p[i].first && p[sig].first > p[i].first){
            if(p[i].first != 0) p[i].first = 1;
        } else {
            int mini= min(p[prev].first, p[sig].first);
            p[i].first = mini + 1;
        }
    }

    //segunda iteracion
    for(int i=pivot-1; i!=pivot; i--){
        if(i == -1) i = n-1;
        int sig = (i+1)%n, prev = (i-1 >= 0) ? i-1 : n-1;
        
        if(p[i].first > p[sig].first && p[i].first > p[prev].first){
            p[i].first = max(p[sig].first, p[prev].first) + 1;
        } else if(p[prev].first > p[i].first && p[sig].first > p[i].first){
            if(p[i].first != 0) p[i].first = 1;
        } else {
            int mini= min(p[prev].first, p[sig].first);
            p[i].first = mini + 1;
        }    
    }

    //segunda iteracion
    for(int i=0; i<n; i++){
        
    }
    return 0;
}
