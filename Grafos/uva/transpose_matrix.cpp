#include <bits/stdc++.h>
using namespace std;

int main(){
    
    int n,m;

    while(cin>>m>>n){
        vector<vector<int>> matrix(m, vector<int>(n, 0));
        for(int i=0; i<m; i++){
            int r; cin>>r;
            vector<int> positions(r);
            for(int j=0; j<r; j++){
                int elem; cin>>elem;
                positions[j] = elem;
            }

            for(int j=0; j<r; j++){
                int elem; cin>>elem;
                matrix[i][positions[j]-1] = elem;
            }
        }
        //cout<<"matriz: "<<endl;
        cout<<n<<" "<<m<<endl;
        for(int i=0; i<n; i++){
            vector<int> elems, indices;
            for(int j=0; j<m; j++){
                
                if(matrix[j][i] != 0){
                    elems.push_back(matrix[j][i]);
                    indices.push_back(j);
                }
                
                //cout<<matrix[j][i]<<" ";
            }
            if(indices.size() != 0)
				cout<<indices.size()<<' ';
			else{
				cout<<"0\n\n";
				continue;
			}
            for(int z=0; z<indices.size(); z++){
                if(z > 0) cout<<' ';
                cout<<indices[z]+1;
            }
            cout<<"\n";
            for(int z=0; z<elems.size(); z++){
                if(z > 0) cout<<' ';
                cout<<elems[z];
            }
            cout<<"\n";
        }
    }
    return 0;
}
