/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool sol(TreeNode* node, int tar, int cum){
        if(node == nullptr) return false;
        int sum = node->val + cum;
        if(sum == tar && node->right == nullptr && node->left==nullptr) return true;
        
        return sol(node->left, tar, sum) || sol(node->right, tar, sum);
    }
    
    bool hasPathSum(TreeNode* root, int targetSum) {
        return sol(root, targetSum, 0);
    }
};