#include <bits/stdc++.h>

using namespace std;

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

class Solution {
    public:
  		Node* insert(Node* root, int data) {
            if(root == NULL) {
                return new Node(data);
            } else {
                Node* cur;
                if(data <= root->data) {
                    cur = insert(root->left, data);
                    root->left = cur;
                } else {
                    cur = insert(root->right, data);
                    root->right = cur;
               }

               return root;
           }
        }

    void preOrder(Node *root) {
        stack<Node *> s;
        Node *aux = root; 
        do{
            if(aux != nullptr){
                cout<<aux->data<<" ";
                s.push(aux);
                aux = aux->left;
            } else if(!s.empty()){
                aux = s.top();
                s.pop();
                aux = aux->right;
            }
        } while (!s.empty() || aux != nullptr);
    }

};