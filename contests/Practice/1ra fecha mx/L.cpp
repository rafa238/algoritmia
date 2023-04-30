#include<bits/stdc++.h>
using namespace std;

unordered_set<string> words;

string getStr(deque<char> dq){
    string news= "";
    while(!dq.empty()){
        news += dq.front();
        dq.pop_front();
    }
    //cout<<news<<" ";
    return news;
}

void generate(string s){
    deque<char> dq;
    for(auto elem : s){
        dq.push_back(elem);
    }
    /*while(!dq.empty()){
        cout<<dq.front()<<endl;
        dq.pop_front();
    }*/
    for(int i=0; i<s.size(); i++){
        char last = dq.back();
        dq.pop_back();
        dq.push_front(last);
        string news = getStr(dq);
        words.insert(news);
    }
}

int main(){
    
    int n; cin>>n;
    int ans = 0;
    for(int i=0; i<n; i++){
        string w;
        cin>>w;
        if(words.count(w) == 0){
            ans++;
            generate(w);
        }
    }
    cout<<ans<<endl;
    return 0;
}