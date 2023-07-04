    //https://www.hackerrank.com/contests/cc-problemsolving-2023/challenges/tree-height-of-a-binary-tree
    int height(Node* root) {
        //Base Case 
        // We'll return -1 cause it allows to index our bt by zero
        if(root == NULL){
            return -1;
        }
        
        //we'll return the height of right and left child, adding +1 because we're counting the current node
        int maxHeight = max(height(root->left), height(root->right)) + 1;
        return maxHeight;
    }
/*
    Time complexity: O(n) -> n is the number of nodes
    Space complexity: O(1) -> we are only using a counter for every node
*/