#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> friends;
    int p1,p2,p3,p4;
    scanf("%d %d %d %d", &p1, &p2, &p3, &p4);
    int team1 = p1+p4;
    int team2 = p2+p3;
    int ans = abs(team2 - team1);
    cout<<ans<<endl;
}