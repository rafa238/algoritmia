#include<bits/stdc++.h>
//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=0&problem=3166&mosmsg=Submission+received+with+ID+28293812
using namespace std;
bool comp(const pair<int, string> &p1, const pair<int, string> &p2)
{
    return p1.first < p2.first;
}

int main(){
    int tc; cin>>tc;
    string url;
    int relevance, bestRelevance, i = 0;
    while(tc--){

        //each pair store <relevance, url>
        vector<pair<int, string>> webPages(10);

        for(int j=0; j<10; j++){
            cin>>url>>relevance;
            webPages[j] = make_pair(relevance, url);
        }

        sort(webPages.begin(), webPages.end(), comp);
        
        bestRelevance = webPages[9].first;

        cout<<"Case #"<< ++i << ":" << endl;
        for(auto elem : webPages){
            if( elem.first == bestRelevance){
                cout << elem.second << endl;
            }
        }
    }
    return 0;
}