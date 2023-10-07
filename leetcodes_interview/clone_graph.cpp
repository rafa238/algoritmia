/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<int, Node*> m;

    Node* cloneGraph(Node* node) {
        if(node == nullptr){
            return nullptr;
        }
        Node* nNode = new Node(node->val);
        m[node->val] = nNode;
        for(Node* neighbor : node->neighbors){
            if(m[neighbor->val]){
                nNode->neighbors.push_back(m[neighbor->val]);
                continue;   
            }
            Node* aux = cloneGraph(neighbor);
            nNode->neighbors.push_back(aux);
        }
        return nNode;
    }
};