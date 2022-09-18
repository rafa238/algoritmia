vector<int> postorderTraversal(TreeNode* root) {
    vector<int> ans;
    if (root == NULL)
        return ans;
    stack<TreeNode *> s;
    
    s.push(root);
    TreeNode *prev = nullptr;
    while(!s.empty()){
        TreeNode *curr = s.top(); 
        if(prev==nullptr || prev->left==curr || prev->right==curr){
            if(curr->left){
                s.push(curr->left);
            } else if(curr->right){
                s.push(curr->right);
            } else {
                s.pop();
                ans.push_back(curr->val);
            }
        } else if(prev == curr->left) {
            if(curr->right){
                s.push(curr->right);
            } else {
                s.pop();
                ans.push_back(curr->val);
            }
        } else if(prev == curr->right) {
            s.pop();
            ans.push_back(curr->val);
        }
        prev = curr;
    }
    
    return ans;
}