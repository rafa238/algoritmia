#include<bits/stdc++.h>
using namespace std;
int main (){
    
    int tc;
    scanf ("%d", &tc);
 
    while ( tc-- ) {
        int n, m;
        scanf ("%d %d", &n, &m);
        int matrix [n+1] [m+1];
        for ( int i = 0; i < n; i++ ) {
            for ( int j = 0; j < m; j++ )
                scanf ("%d", &matrix [i] [j]);
        }
 
        bool repeated = true;

        //check edge doesn't have more than two connections
        for ( int i = 0; i < m; i++ ) {
            int sum = 0;
            for ( int j = 0; j < n; j++ ){
                sum += matrix [j] [i];
            }
            if ( sum != 2 ) repeated = false;
        }
 
        bool checked [8 + 3] [8 + 3];
        memset (checked, false, sizeof (checked));
 
        if (repeated) {
            for ( int i = 0; i < m; i++ ) {
                int first, second, j = 0;
                while ( matrix [j++] [i] != 1 );
                first = j - 1;
                while ( matrix [j++] [i] != 1 );
                second = j - 1;
 
                if (!checked [first] [second]){
                    checked [first] [second] = true;
                    checked [second] [first] = true;
                } 
                else repeated = false;
            }
        }
 
        if ( repeated ) printf ("Yes\n");
        else printf ("No\n");
    }
 
    return 0;
}