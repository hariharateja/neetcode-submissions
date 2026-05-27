struct TrieNode{
    TrieNode* children[26];
    bool isendofword;
    TrieNode() {
        isendofword = false;
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
    }
};

class PrefixTree {
private:
    TrieNode* root;
    void clear(TrieNode* node){
        if(!node) return;
        for(int i = 0 ; i < 26 ; i++){
            if(node->children[i]){
                clear(node->children[i]);
            }
        }
        delete node;
    }
public:
    PrefixTree() {
        root = new TrieNode();
    }
    ~PrefixTree() {
        clear(root);
    }
    void insert(string word) {
        TrieNode* current = root;
        for(char c : word){
            int index = c-'a';
            if(current->children[index] == nullptr){
                current->children[index] = new TrieNode();
            }
            current = current->children[index];
        }
        current->isendofword = true;
    }
    
    bool search(string word) {
        TrieNode* current = root;
        for (char ch : word) {
            int index = ch - 'a';
            if (current->children[index] == nullptr) {
                return false;
            }
            current = current->children[index];
        }
        return current->isendofword;
    }
    
    bool startsWith(string prefix) {
        TrieNode* current = root;
        for (char ch : prefix) {
            int index = ch - 'a';
            if (current->children[index] == nullptr) {
                return false;
            }
            current = current->children[index];
        }
        return true;
    }
};
