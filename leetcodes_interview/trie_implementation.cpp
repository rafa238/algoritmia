class TrieNode{
public:
    unordered_map<char, TrieNode*> children;
    bool endOfWord;

    TrieNode(){
        endOfWord = false;
    }

};

class Trie {
private:
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* aux = root;
        for(char character : word){
            auto it = aux->children.find(character);
            if(it == aux->children.end()) {
                TrieNode* node = new TrieNode();
                aux->children[character] = node;
            }
            aux = aux->children[character];
        }
        aux->endOfWord = true;
    }
    
    bool search(string word) {
        TrieNode* aux  = root;
        for(char character : word){
            auto it = aux->children.find(character);
            if(it == aux->children.end()){
                return false;
            }
            aux = aux->children[character];
        }
        return aux->endOfWord;
    }
    
    bool startsWith(string prefix) {
        TrieNode* aux = root;
        for(char character : prefix){
            auto it = aux->children.find(character);
            if(it == aux->children.end()){
                return false;
            }
            aux = aux->children[character];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */