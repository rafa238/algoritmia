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
    vector<int> rightSideView(TreeNode* root) {
        if(root == NULL){
            return {};
        }
        //queue of node, level
        queue<pair<TreeNode*, int>> q;
        stack<pair<TreeNode*, int>> rightMosts;
        q.push({root, 0});
        rightMosts.push({root, 0});
        while(!q.empty()){
            pair<TreeNode*, int> node_lvl = q.front();
            q.pop();

            TreeNode* currNode = node_lvl.first;
            int currLvl = node_lvl.second;
            //enqueue left side
            if(currNode->left != NULL){
                q.push({currNode->left, currLvl+1});
            }

            //enqueue right side
            if(currNode->right != NULL){
                q.push({currNode->right, currLvl+1});
            }

            //update rightMosts
            if(rightMosts.top().second == currLvl){
                rightMosts.pop();
            }
            rightMosts.push(node_lvl);
        }
        vector<int> answer;
        while(!rightMosts.empty()){
             pair<TreeNode*, int> node_lvl = rightMosts.top();
             rightMosts.pop();

             TreeNode* currNode = node_lvl.first;
            answer.push_back(currNode->val);
        }
        reverse(answer.begin(), answer.end());
        return answer;
    }
    
};