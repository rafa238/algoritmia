#include <bits/stdc++.h>
using namespace std;

int main(){
    int tc, p; scanf("%d", &tc);
    
    while(tc--){
        string s;
        scanf("%d", &p);
        getchar();
        //vector<vector<int>> graph(p);
        int minimo=INT_MAX;
        vector<int> nums;
        for (int i=0; i<p; i++){
            getline(cin, s);
            int cont=0;
            for(int j=0; j<s.size(); j++){
                if(s[j] != ' '){
                    //cout<<s[j];
                    cont++;
                }
                //cout<<"elem : "<<s[j];
            }
            minimo = min(cont, minimo);
            nums.push_back(cont);
            //cout<<"endl";
        }
        //cout<<minimo<<" ";
        for (int i=0; i<nums.size(); i++){
            //cout<<nums[i];
            if(nums[i] == minimo){
                cout<<i+1;
                if(i!=nums.size()-1) cout<<" ";
                else cout<<"\n";
                
            }
        }

    }
    return 0;
}