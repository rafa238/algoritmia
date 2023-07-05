//its balanced, lowest element & greatest element in the subtree 
    bool checkBST2(Node* root, int maxP, int minP){
        if(root == NULL){
            return true;
        }
        bool left = checkBST2(root->left, root->data, minP);
        bool right = checkBST2(root->right, maxP, root->data);
        
        
        return left && right && root->data < maxP && root->data > minP;
    }

	bool checkBST(Node* root) {
        bool ans = checkBST2(root, 999999, -999999);
        
        return ans;
    }