//https://leetcode.com/problems/max-area-of-island/submissions/
class Solution {
    
    
int sumNumbers(TreeNode root) {
    int sum=0;
    dfs(root, 0, sum);
    return sum;
}

void dfs(TreeNode nodo, int pathSum, int &sum){
    if(nodo == null) return;
    int valor_nodo = nodo.val;
    pathSum = pathSum*10 + valor_nodo;
    if(nodo.left == null && nodo.right == null){
        sum += pathSum;
        return;
    }
    dfs(nodo.left, pathSum, suma_total);
    dfs(nodo.right, pathSum, suma_total);
}



}
