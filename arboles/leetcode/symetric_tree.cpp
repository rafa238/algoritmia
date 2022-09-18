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
    
    bool espejo(TreeNode* node1, TreeNode* node2){
        if(node1 == nullptr && node2==nullptr ) return true;
        if(node1 && node2 &&node1->val == node2->val){
            return espejo(node1->right, node2->left) && espejo(node1->left, node2->right);
        } else {
            return false;
        }
    }
    
    bool isSymmetric(TreeNode* root) {
        return espejo(root->left, root->right);
        
        
    }
};