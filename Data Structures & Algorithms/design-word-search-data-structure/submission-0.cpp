#include <string>
#include <vector>

using namespace std;

struct TrieNode {
    TrieNode* children[26];
    bool isEndOfWord;

    TrieNode() {
        isEndOfWord = false;
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
    }
};

class WordDictionary {
private:
    TrieNode* root;

    // Helper function for recursive backtracking search
    bool searchInNode(string& word, int index, TrieNode* current) {
        // If we reached the end of the word, check if it forms a valid word
        if (index == word.length()) {
            return current->isEndOfWord;
        }

        char ch = word[index];

        // If it's a wildcard dot, we must try all 26 possible paths
        if (ch == '.') {
            for (int i = 0; i < 26; i++) {
                if (current->children[i] != nullptr) {
                    // If any path down the tree returns true, we found a match
                    if (searchInNode(word, index + 1, current->children[i])) {
                        return true;
                    }
                }
            }
            return false; // None of the paths matched
        } 
        // If it's a regular character, follow the standard Trie path
        else {
            int childIndex = ch - 'a';
            if (current->children[childIndex] == nullptr) {
                return false; // Path doesn't exist
            }
            return searchInNode(word, index + 1, current->children[childIndex]);
        }
    }

    // Clean up memory
    void clear(TrieNode* node) {
        if (!node) return;
        for (int i = 0; i < 26; i++) {
            clear(node->children[i]);
        }
        delete node;
    }

public:
    WordDictionary() {
        root = new TrieNode();
    }

    ~WordDictionary() {
        clear(root);
    }
    
    void addWord(string word) {
        TrieNode* current = root;
        for (char ch : word) {
            int index = ch - 'a';
            if (current->children[index] == nullptr) {
                current->children[index] = new TrieNode();
            }
            current = current->children[index];
        }
        current->isEndOfWord = true;
    }
    
    bool search(string word) {
        // Start the recursive search from the root and index 0
        return searchInNode(word, 0, root);
    }
};