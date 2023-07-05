/*
 it is also bst if inorder traversal give us a sorted array
 lets make a inorder traversal and check if it is in indecreasing order
 Time O(n) -> n is the number of nodes
 Space O(n)
*/
    void inorder(Node* root, vector<int> &inArr){
        if(root == NULL){
            return;
        }
        inorder(root->left, inArr);
        inArr.push_back(root->data);
        inorder(root->right, inArr);
    }

	bool checkBST(Node* root) {
        vector<int> in;
        inorder(root, in);
        bool answer = true;
        for(int i=0;i < in.size()-2; i++){
            if(in[i] >= in[i+1]){
                answer = false;
                break;
            }
        }
        return answer;
    }