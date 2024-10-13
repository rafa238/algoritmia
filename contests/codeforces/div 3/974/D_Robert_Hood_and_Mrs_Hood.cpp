#include <bits/stdc++.h>

using namespace std;


int main(){
    int tc; cin >> tc;
    while(tc--){
        int n, d, k;
        cin >> n >> d >> k;
        vector<pair<int, int>> intervals;
        for(int i = 0; i < k; i++) {
            int ai, bi; cin >> ai >> bi;
            intervals.push_back({ai, bi});
        }
        sort(intervals.begin(), intervals.end());

        //sweep line
        map<int, int> open, close;
        for(auto& p : intervals){
            ++open[p.first];
            ++close[p.second];
        }
        int max_overlap = INT_MIN;
        int min_overlap = INT_MAX;
        int count = 0;
        int bro_i = 0, mo_i = 0;
        
        //initialize window
        for(int i = 1; i < d; i++) {
            if(open.count(i) != 0) {
                count += open[i];
            }
        }
        int l = 1, r = d;
        while(r <= n) {
            if(open.count(r) != 0) {
                count += open[r];
            }
            if(count > max_overlap) {
                max_overlap = max(count, max_overlap);
                bro_i = l;
            }
            if(count < min_overlap) {
                min_overlap = min(count, min_overlap);
                mo_i = l;
            }
            
            if(close.count(l) != 0) {
                count -= close[l];
            }
            l++;
            r++;
        }
        cout << bro_i << " " << mo_i  << endl;

    }
    return 0;
}