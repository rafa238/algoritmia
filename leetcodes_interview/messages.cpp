#include<bits/stdc++.h>

using namespace std;

unordered_set<string> getMentions(string message) {
    unordered_set<string> mentions;
    for(int i = 0; i < message.size(); i++) {
        if(message[i] != '@') continue;
        string currMention = "";
        for(int j = i + 1; j < message.size(); j++, i++){
            if(message[j] == ',') {
                mentions.insert(currMention);
                currMention = "";
                continue;
            } 
            if (message[j] == ' ') {
                mentions.insert(currMention);
                break;
            }
            currMention += message[j];
        }
    }
    return mentions;
}

bool compare(const pair<string, int>& a, const pair<string, int>& b) {
    if (a.second == b.second) {
        return a.first < b.first; // Orden lexicográfico si las frecuencias son iguales
    }
    return a.second > b.second; // Orden descendente por frecuencia
}

vector<string> messageStatistics(vector<string> users, vector<string> messages) {
    map<string, int> freq;
    for (string user : users) {
        freq[user] = 0;
    }
    for (string message : messages) {
        unordered_set<string> mentions = getMentions(message);
        for (string mention : mentions) {
            if (freq.count(mention) != 0) {
                freq[mention]++;
            }
        }
    }

    vector<pair<string, int>> freqVec(freq.begin(), freq.end());
    sort(freqVec.begin(), freqVec.end(), compare);

    vector<string> statistics;
    for (const auto& p : freqVec) {
        string statistic = p.first + "=" + to_string(p.second);
        statistics.push_back(statistic);
    }
    return statistics;
}

int main(){
    vector<string> users = {"id123", "id234", "id7", "id321"};
    vector<string> messages = {
        "Hey @id123,id321 @@@review this PR please! @id123 what do you think about this approach?", 
        "Hey @id7 nice approach! Great job! @id800 what do you think?", 
        "@id123,id321 thx!"
    };
    vector<string> answer = messageStatistics(users, messages);
    cout << "[ ";
    for(string s : answer){
        cout << s << ",";
    }

    cout << "]";
    return 0;
}