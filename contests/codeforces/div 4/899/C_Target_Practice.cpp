#include<bits/stdc++.h>

using namespace std;

int main(){
    int tc; cin >> tc;

    while(tc--) {
        int sum = 0;
        for(int i = 0; i<10; i++) {
            for(int j = 0; j<10; j++) {
                char elem; 
                cin>> elem;
                if( elem != 'X') continue;
                if(i == 0 || i == 9 || j == 0 || j == 9) {
                    sum += 1;
                } else if( (i == 1  && ( 1 <= j && j <= 8)) || 
                (i == 8  && (1 <= j && j <= 8 )) ||
                (j == 1  && ( 1 <= i && i <= 8)) || 
                (j == 8  && (1 <= i && i <= 8 ))
                ) {
                    sum += 2;
                } else if( (i == 2  && ( 2 <= j && j <= 7)) || 
                (i == 7  && (2 <= j && j <= 7 )) ||
                (j == 2  && ( 2 <= i && i <= 7)) || 
                (j == 7  && (2 <= i && i <= 7 ))
                ) {
                    sum += 3;
                } else if( (i == 3  && ( 3 <= j && j <= 6)) || 
                (i == 6  && (3 <= j && j <= 6 )) ||
                (j == 3  && ( 3 <= i && i <= 6)) || 
                (j == 6  && (3 <= i && i <= 6 ))
                ) {
                    sum += 4;
                } else if( (i == 4  && ( 4 <= j && j <= 5)) || 
                (i == 5  && ( 4 <= j && j <= 5 )) ||
                (j == 4  && ( 4 <= i && i <= 5)) || 
                (j == 5  && ( 4 <= i && i <= 5 ))
                ) {
                    sum += 5;
                } 
            }
        }
        cout << sum << endl;
    }
    return 0;
}