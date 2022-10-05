#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
	int n; cin>>n;
	int score, minRecord, maxRecord, situation=0;
    cin>>score;
    minRecord = score;
    maxRecord = score;
	for (int i=0; i<n-1; i++) {
		cin>>score;
        if(score > maxRecord){
			maxRecord = score;
			situation++;
		} else if (score < minRecord) {
			minRecord=score;
			situation++;
		}
	}
	cout<<situation<<endl;
	return 0;
}
 