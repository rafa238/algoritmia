#include <bits/stdc++.h>
using namespace std;

int search(vector<int> v, int target){
    int index = -1;
    for (int i = 0; i < v.size(); i++){
        if (v[i] == target){
            index = i;
        }
    }
    return index;
}

void makePosOrder(vector<int> inorder, vector<int> preorder, vector<int> &ans){
    if(inorder.size() == 0){
        return;
    }
    int preorderRoot = preorder[0];
    int inorderRoot = search(inorder, preorderRoot);

    // left
    if (inorderRoot != 0){
        vector<int> inorderLeft(inorder.begin(),
                                inorder.begin() + inorderRoot);
        vector<int> preorderLeft(preorder.begin() + 1,
                                 preorder.begin() + inorderRoot + 1);

        makePosOrder(inorderLeft, preorderLeft, ans);
    }

    //right
    if(inorderRoot != inorder.size()-1){
        vector<int> inorderRight(inorder.begin() + inorderRoot + 1,
                             inorder.end());
        vector<int> preorderRight(preorder.begin() + inorderRoot + 1,
                                preorder.end());
        makePosOrder(inorderRight, preorderRight, ans);
    }
    
    ans.push_back(preorderRoot);
}

int main(){
    int n;
    cin >> n;
    vector<int> inorder(n), preorder(n);
    
    for (int i = 0; i < n; i++)
    {
        cin >> preorder[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> inorder[i];
    }
    vector<int> posOrder;
    makePosOrder(inorder, preorder, posOrder);
    for(auto elem : posOrder){
        cout<<elem<<" ";
    }
    return 0;
}