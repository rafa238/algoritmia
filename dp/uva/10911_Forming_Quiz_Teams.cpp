#include <bits/stdc++.h>
//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=779&page=show_problem&problem=1852
#define INF 100000000
using namespace std;

struct Elem{
    string name;
    int x, y;
};

vector<Elem> elems;
int n;
vector<double> dp;
vector<vector<double>> dist;

double solve(int mask){
    if(mask == ((1<<(2*n))-1)) return 0;
    if(dp[mask] != -1) return dp[mask];
    double ans = 1<<30;
    for(int i=0; i<2*n; i++){
        if(mask & (1<<i)) continue;
        for(int j=i+1; j<2*n; j++){
            if(mask & (1<<j)) continue;
            //cout<<(nMask|(1<<j))<<" ";
            //cout<<(nMask|(1<<j))<<" ";
            ans = min(dist[i][j] + solve(mask|(1<<i)|(1<<j)), ans);
        }
    }
    return dp[mask] = ans;
}

int main(){
    string name;
    int x, y;
    int kase = 1;
    while(cin>>n && n != 0){
        elems.clear();
        elems.resize(n*2);
        dp.clear();    
        dp.resize(1<<(2*n), -1);
        dist.clear();
        dist.resize(2*n, vector<double>(2*n));
        for(int i=0; i<(2*n); i++){
            cin>>name>>x>>y;
            elems[i] = Elem{name, x, y};
        }

        for(int i=0; i<dist.size(); i++){
            for(int j=i+1; j<dist[i].size(); j++){
                dist[i][j] = dist[j][i]= hypot(elems[i].x-elems[j].x, elems[i].y-elems[j].y);
            }
        }
        printf("Case %d: %.2lf\n",kase++,solve(0));
    }
    return 0;
}