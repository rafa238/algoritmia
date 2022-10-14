vector<int> inorderTraversal(TreeNode* root) {
    stack<TreeNode *> s;
    TreeNode *aux = root; 
    vector<int> ans;
    do{
        if(aux != nullptr){
            s.push(aux);
            aux = aux->left;
        } else if(!s.empty()){
            aux = s.top();
            s.pop();
            ans.push_back(aux->val);
            aux = aux->right;
        }
    } while (!s.empty() || aux != nullptr);
    return ans;
}