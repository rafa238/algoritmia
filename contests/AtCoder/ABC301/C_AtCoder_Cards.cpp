#include <bits/stdc++.h>

using namespace std;

int main(){
    string s1, s2; 
    cin>>s1>>s2;
    set<char> sust = {'a', 't', 'c', 'o', 'd', 'e', 'r'};
    unordered_map<char, int> freq;
    int ats1 = 0, ats2 = 0;
    for(int i=0; i<s1.size(); i++){
        char a = s1[i];
        char b = s2[i];
        if(a == '@') ats1++;
        else freq[a]++;
        if(b == '@') ats2++;
        else freq[b]--;
    }
    bool flag = true;
    for(auto elem : freq){
        if(sust.count(elem.first) == 0 && (elem.second != 0)){
            flag = false;
            break;
        }
        if(elem.second < 0) ats1 += elem.second;
        if(elem.second > 0) ats2 -= elem.second;
    }
    //cout<<ats1<<" "<<ats2;
    if(ats1 < 0 || ats2 < 0){
        flag = false;
    }
    
    cout<<((flag)?"Yes":"No")<<endl;
    return 0;
}