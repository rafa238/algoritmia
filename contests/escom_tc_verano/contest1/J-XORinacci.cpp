#include <bits/stdc++.h>
#define fastIO()                  \
    ;                             \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
using namespace std;
typedef long long ll;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll a, b, n;
        cin >> a >> b >> n;
        ll c = a ^ b;
        ll m = n % 3;
        if (m == 0)
        {
            cout << a << '\n';
        }
        else if (m == 1)
        {
            cout << b << '\n';
        }
        else
        {
            cout << c << '\n';
        }
    }
    return 0;
}