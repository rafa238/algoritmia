#include<bits/stdc++.h>
using namespace std;
 
int main(){
  int n, a, b, ci;
  cin>>n>>a>>b;
  for(int i=1; i<=n; i++){
    	cin>>ci;
    	if(ci == (a+b))
			cout<<i<<"\n";
  }
  return 0; 
}