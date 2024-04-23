#include <bits/stdc++.h>

using namespace std;

const int LIMIT = 1e5 + 7;
vector<int> generate_binary_decimals() {
    vector<int> binary_decimals;
    queue<int> q;
    q.push(1);
    while (!q.empty()) {
        int current = q.front();
        q.pop();
        if(current != 1)
            binary_decimals.push_back(current);
        if (current * 10 <= LIMIT) {
            q.push(current * 10);
        }
        if (current * 10 + 1 <= LIMIT) {
            q.push(current * 10 + 1);
        }
    }
    return binary_decimals;
}

bool is_ok(vector<int> &binary_decimals, int n) {
    if(n == 1) return true;
    bool ans = false;
    for(int &num : binary_decimals) {
        if(n % num == 0) {
            ans = ans || is_ok(binary_decimals, (n / num));
        }
    }
    return ans;
}

int main() {
    vector<int> binary_decimals = generate_binary_decimals();
    int tc; cin >> tc;
    while(tc--) {
        int n; cin >> n;
        if(is_ok(binary_decimals, n)) {
            cout << "YES";
        } else {
            cout << "NO";
        }
        cout << endl;
    }   
    return 0;
}