#include <bits/stdc++.h>

using namespace std;

int main(){
    int N; cin>>N;
    for(int i=0; i<N; i++){
        string text;
        cin>>text;
        if (text == string(text.rbegin(), text.rend())) {
            cout << "Case " << i +1<< ": Yes" << endl;
        } else {
            cout << "Case " << i+1 << ": No" << endl;
        }
    }
}