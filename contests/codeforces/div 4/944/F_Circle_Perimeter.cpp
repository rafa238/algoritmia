#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;


int main() {
    int tc; cin >> tc;
    while(tc--) {
        ll point; cin >> point;

        vector<ll> points;
        for(int i = 1; i<=point; i++) {
            points.push_back((point * point) + (i*i));
        }
        ll target = (point + 1) * (point + 1);

        int l = 0, r = (int)points.size() - 1, ans;
        while (l <= r) {
            int m = (l+r)/2;
            if(points[m] <= target) {
                ans = m;
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        if(points[ans] == target) {
            ans--;
        }
        ll result = ans;
        if(ans == points.size() - 1) {
            result -= 1;
        }
        result++;
        result *= 2;
        result *= 4;
        if(ans == points.size() - 1) {
            result += 4;
        }
        result += 4;
        //result *= 4; 
        //result += 4;
        /**/
        cout << result << endl;
    }
    return 0;
}


/*


int point; cin >> point;
        if(point == 1) {
            cout << 8 << endl;
            continue;
        }
        vector<ll> points;
        for(int i = 1; i<=point; i++) {
            points.push_back(i*i);
        }
        ll target = (point + 1)*(point + 1) - point*point;
        int l = 0, r = (int)points.size() - 1, ans;
        while (l <= r) {
            int m = (l+r)/2;
            if(points[m] <= target) {
                ans = m;
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        int result = (ans + 1) * 8 + 4;
        if(ans == points.size() - 1) {
            result += 4;
        }
        if(points[ans] == target) {
            ans--;
        }
        //cout << ans << endl;
        cout << (ans) * 8 + 4<< endl;
*/