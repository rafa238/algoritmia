#include<bits/stdc++.h>
//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=608&page=show_problem&problem=2595
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, budget, hotels, weeks, Hcost, ans;
    bool haveAnswer;
    while(cin >> n >> budget >> hotels >> weeks){
        ans = INT_MAX;
        haveAnswer = false;
        while(hotels--){
            vector<int> beds(weeks);
            
            //receive data
            cin >> Hcost;
            for(int i=0; i<weeks; i++){
                cin>>beds[i];
            }

            //Is the hotel a possible option? (Whitin budget and enough beds)
            if(n*Hcost <= budget){
                for(int i=0; i<weeks; i++){
                    if(beds[i] >= n){
                        haveAnswer = true;
                        ans = min(ans, n*Hcost);
                    }
                }
            }
        }
        cout<<((haveAnswer) ? to_string(ans) : "stay home")<<endl;
    }
    return 0;
}