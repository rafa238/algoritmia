#include <bits/stdc++.h>

using namespace std;

int main(){
    int tc, sum = 0;
    cin >> tc;
    vector<string> names;
    for(int i = 0; i<tc; i++) {
        string name; cin >> name;
        int score; cin >> score;
        names.push_back(name);
        sum += score;
    }
    sort(names.begin(), names.end());
    int winner_pos = sum % tc;
    cout << names[winner_pos] << endl;

    return 0;
}