#include<bits/stdc++.h>
//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=608&page=show_problem&problem=1055
using namespace std;

void solve(int currMonth, double car, double loan, double payment, vector<double> &depres){
    loan -= payment;  
    car *= (1-depres[currMonth]);
    if(loan  < car){
        cout << currMonth << ((currMonth == 1) ? " month" : " months") << endl;
        return;
    }
    solve(currMonth + 1, car, loan, payment, depres);
}

int main(){
    int months, rec;
    double downp, loan;
    while(cin>>months>>downp>>loan>>rec, months > 0){
        vector<double> depres(110, 0);
        for(int i=0; i<rec; i++){
            int month;
            double depre;
            cin>>month>>depre;
            
            depres[month] = depre;
        }
        
        double prev = depres[0];
        for(int i=0; i<depres.size(); i++){
            if(depres[i] != 0){
                prev = depres[i];
            } else {
                depres[i] = prev;
            }
        }
        
        double car = (downp + loan)*(1-depres[0]);
        if(loan < car) cout<<"0 months"<<endl;
        else solve(1, car, loan, loan / months, depres);
    }
    
    return 0;
}