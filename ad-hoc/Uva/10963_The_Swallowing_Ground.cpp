#include<bits/stdc++.h>
//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=608&page=show_problem&problem=1904
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0);

    int tc; cin>>tc;
    while(tc--){
        int w; cin>>w;
        int y1, y2, gap;
        bool flag = true;

        cin>>y1>>y2;
        gap = y1-y2;
        for(int i=0; i<w-1; i++){
            cin>>y1>>y2;
            if(gap != y1-y2){
                flag = false;
            }
        }
        cout<<((flag) ? "yes" : "no")<<endl;
        if(tc) cout<<endl;
    }
    return 0;
}