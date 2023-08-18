class Solution {
public:
    void countGoodNodes(TreeNode* curr, int greatestParent, int &goodNodes){
        if(curr == nullptr){
            return;
        }
        if(curr->val >= greatestParent){
            goodNodes++;
        }
        countGoodNodes(curr->left, max(greatestParent, curr->val), goodNodes);
        countGoodNodes(curr->right, max(greatestParent, curr->val), goodNodes);
    }

    int goodNodes(TreeNode* root) {
        int amountGoodNodes = 0;
        countGoodNodes(root, root->val, amountGoodNodes);
        return amountGoodNodes;
    }
};