#include <bits/stdc++.h>
using namespace std;

int main(){
    int tc; scanf("%d", &tc);
    
    while(tc--){
        int p;
        scanf("%d", &p);
        getchar();
        int minimo=INT_MAX;
        p++;
        vector<int> nums(p, 0);
        for (int i=1; i<p; i++){
            string s;
            getline(cin, s);
            int cont=1;
            for(int j=0; j<s.length(); j++){
                if(s[j] == ' '){
                    cont++;
                }
            }
            nums[i] = cont;
            minimo = min(cont, minimo);
            
        }
        vector<int> ans;
        for (int i=1; i<p; i++){
            if(nums[i] == minimo){
                ans.push_back(i);
                //cout<<i+1<<(i!=nums.size()-1 ? " ":"\n");
                
            }
        }
        for (int i=0; i<ans.size(); i++){
            cout<<ans[i]<<(i!=ans.size()-1 ? " ":"\n");
        }

    }
    return 0;
}
