//CUT THE RIBBON
#include<bits/stdc++.h>
using namespace std;
int cortar(int n,int a, int b, int c){
    int ans=0;
    for(int i=0;i<4001;i++){
        for(int j=0;j<4001;j++){
            int zc = n-(a*i)-(b*j);
            if(zc<0)break;
            double z = (zc/(double)c);
            if (z==(int)z){
               ans=max(ans,static_cast<int>(z+i+j));
            }
        }
    }
    return ans;
}

int main()
{
    int n,a,b,c;
    cin>>n>>a>>b>>c;
    cout<<cortar(n,a,b,c);
    return 0;
}

/*
//CUT THE RIBBON BACKTRACKING
int dp[4000+13];

int cortes(int n, set<int> abc){
    if(dp[n] != -1) return dp[n];
    if(n < 0){
        return 0;
    } else if (n==0){
        return 1;
    }
    int sum = 0;
    for (const int number : abc) {
        sum += cortes(n-number, abc);
        dp[n] = sum;
    }
    return sum;
}

int main()
{
    set<int> abc;
    int n,a,b,c;
    cin>> n;
    int i=0, cort=0;
    while(i<3){
        int a;
        cin >> a;
        abc.insert(a);
        if(a==n) cort--;
        i++;
    }
    memset (dp, -1 ,sizeof(dp));

    if(abc.size() == 1){
        cout<<1;
    } else {
        cort += cortes(n, abc);
        cout<< cort;
    }
    return 0;
}
*/