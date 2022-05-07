/**
 * https://leetcode.com/problems/binary-tree-right-side-view/
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
    
    void recorrer(TreeNode *nodo, vector<int> &vec){
        vec.push_back(nodo->val);
        if(nodo->right != NULL) recorrer(nodo->right, vec);
    }
    
    vector<int> rightSideView(TreeNode* root) {
        vector<int> vec;
        recorrer(root, vec);
        return vec;
    }
    
};
