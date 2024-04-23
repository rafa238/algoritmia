#include <bits/stdc++.h>

using namespace std;

int main(){
    int tc; cin >> tc;

    while(tc--) {
        int hour, minuts;
        scanf("%d:%d", &hour, &minuts);
        if(hour == 0) {
            printf("12:%02d AM", minuts);
            //cout << "12:"<< minuts << " AM";
        } else if(hour < 12) {
            printf("%02d:%02d AM", hour, minuts);
            //cout << hour << ":" << minuts << " AM";
        } else if(hour == 12) {
            printf("%02d:%02d PM", hour, minuts);
        } else {
            //cout << hour % 12 << ":" << minuts << " PM";
            printf("%02d:%02d PM", hour % 12, minuts);
        }
        cout << endl;
    }

    return 0;
}