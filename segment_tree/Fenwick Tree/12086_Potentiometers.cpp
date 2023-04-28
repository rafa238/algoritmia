#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
#define LSOne(a) (a & -(a))

class FenwickTree{
    private:
        vi ft;
    public:
        FenwickTree(int n){
            ft.assign(n+1, 0);
        }

        int rsq(int b){
            int sum=0;
            for(; b; b -= LSOne(b)){
                sum += ft[b];
            }
            return sum;
        }

        int rsq(int a, int b){
            return rsq(b) - rsq(a-1);
        }

        void update(int k, int v){
            for(;k < (int)ft.size(); k += LSOne(k)){
                ft[k] += v;    
            }
        }
};

int main(){
    int n, cont = 0;
    while(cin>>n && n != 0){
        getchar();
        ++cont;
        if(cont > 1)puts("");
        cout<<"Case "<<cont<<":"<<endl;
        FenwickTree ft(n+1);
        for(int i=1; i<=n; i++){
            int pot;
            cin>>pot;
            getchar();
            ft.update(i, pot);
        }
        
        string q;
        while(getline(cin, q) && q != "END"){
            char op;
            int l, r;
            sscanf(q.c_str(), "%c %d %d", &op, &l, &r);
            //cout<<q<<endl;
            if(op == 'M'){
                int ans = ft.rsq(l, r);
                cout<<ans<<endl;
            } else  {
                //cout<<"update "<<l<<" "<<r<<endl;
                ft.update(l,r - (ft.rsq(l) - ft.rsq(l - 1)));
            }
        }
    }
    return 0;
}