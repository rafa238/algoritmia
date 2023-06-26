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
    

    int countLevels(TreeNode* root, bool &isBalanced){
        if(root == nullptr){
            return 0;
        }
        int leftSide = countLevels(root->left, isBalanced);
        int rightSide = countLevels(root->right, isBalanced);
        if(abs(leftSide-rightSide) > 1){
            isBalanced = false;
        }
        return max(leftSide+1, rightSide+1);
    }

    bool isBalanced(TreeNode* root) {
        bool isBalanced = true;
        countLevels(root, isBalanced);
        return isBalanced;
    }
};