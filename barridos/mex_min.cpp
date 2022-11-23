#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int &x : a)
        cin >> x;
    vector<vector<int>> p(n + 1, {0});
    for (int i = 0; i < n; i++)
        p[a[i]].push_back(i + 1);
    for (int i = 0; i < n + 1; i++)
        p[i].push_back(n + 1);

    for(auto vec:p){
        for(auto elem: vec){
            cout<<elem;
        }
        cout<<endl;
    }
    for (int i = 0; i < n + 1; i++)
    {
        int mx = -1;
        for (int j = 1; j < p[i].size(); j++)
            mx = max(mx, p[i][j] - p[i][j - 1] - 1);
        if (mx >= m)
        {
            cout << i << '\n';
            return 0;
        }
    }
}