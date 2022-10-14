#include <bits/stdc++.h> 
using namespace std;

int main(){
	string s, letras = "hello";
  	int i, aux =0;
  
  	cin >> s;
  
	for(i=0; i<s.size();i++){
      if(s.at(i) == letras.at(aux)){
      	aux++;
      }
      if(aux == 5) break;
    }
  
  if(aux == 5) cout << "YES" << "\n";
  else cout << "NO" << "\n";
  return 0;
}