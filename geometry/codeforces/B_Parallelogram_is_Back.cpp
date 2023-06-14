#include<bits/stdc++.h>
using namespace std;

int main(){
    pair<int, int> vec1, vec2, vec3;
    cin>>vec1.first>>vec1.second;
    cin>>vec2.first>>vec2.second;
    cin>>vec3.first>>vec3.second;

    cout<<3<<"\n";
    cout<<vec1.first-vec3.first+vec2.first<<" "<<vec1.second-vec3.second+vec2.second<<"\n";
    cout<<vec1.first-vec2.first+vec3.first<<" "<<vec1.second-vec2.second+vec3.second<<"\n";
    
    cout<<vec2.first-vec1.first+vec3.first<<" "<<vec2.second-vec1.second+vec3.second<<"\n";
    
    return 0;
}