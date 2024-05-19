#include <bits/stdc++.h>

using namespace std;

int main(){
    int n; cin >> n;
    vector<pair<int, int>> cards(n);
    map<pair<int, int>, int> cards_positions;
    for(int i = 0; i < n; i++) {
        cin >> cards[i].first >> cards[i].second;
        cards_positions[cards[i]] = i;
    }
    sort(cards.begin(), cards.end());
    reverse(cards.begin(), cards.end()); 

    int comp = cards[0].second;
    for(int i = 1; i<n; i++) {
        if(cards[i].second > comp) {
            cards_positions[cards[i]] = -1;
            continue;
        }
        comp = cards[i].second;
    }
    vector<int> ans;
    for(auto &elem : cards_positions) {
        if(elem.second != -1) {
            ans.push_back(elem.second);
        }
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for(auto elem : ans) {
        cout << elem + 1 << " ";
    }
    return 0;
}