class Solution {
public:
    void preorder(TreeNode* root, vector<int> &answer) {
        if(root == nullptr) {
            return;
        }
        preorder(root->left, answer);
        answer.push_back(root->val);
        preorder(root->right, answer);
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        vector<int> traversal;
        preorder(root, traversal);
        int sum = 0;
        for(int i = 0; i<traversal.size(); i++) {
            if( low <= traversal[i] && traversal[i] <= high ) {
                sum += traversal[i];
            }
        }
        return sum;
    }
};
