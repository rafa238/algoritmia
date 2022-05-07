/**
*https://leetcode.com/problems/sum-root-to-leaf-numbers/submissions/
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    int sumNumbers(TreeNode root) {
        int sum;
        dfs(root, 0, sum);
        return sum;
    }
    
    void dfs(TreeNode nodo, int pathSum, int &suma_total){
        if(nodo == nullptr) return;
        int valor_nodo = nodo->val;
        pathSum = pathSum*10 + valor_nodo;
        if(nodo->left == nullptr && nodo->right == nullptr){
            suma_total += pathSum;
            return;
        }
        dfs(nodo.left, pathSum, suma_total);
        dfs(nodo.right, pathSum, suma_total);
    }
}