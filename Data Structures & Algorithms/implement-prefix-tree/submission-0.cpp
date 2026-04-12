class TrieNode {
public:
    TrieNode* children[26];
    bool isLeaf;

    TrieNode() {
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        isLeaf = false;
    }
};

class PrefixTree {
public:
    TrieNode* trie;

    PrefixTree() {
        trie = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* node = trie;
        for (int i = 0; i < word.length(); i++) {
            if (node->children[word[i]-'a'] != NULL) {
                node = node->children[word[i]-'a'];
            } else {
                node->children[word[i]-'a'] = new TrieNode();
                node = node->children[word[i]-'a'];
            }
        }
        node->isLeaf = true;
    }
    
    bool search(string word) {
        TrieNode* node = trie;
        for (int i = 0; i < word.length(); i++) {
            if (node->children[word[i]-'a'] != NULL) {
                node = node->children[word[i]-'a'];
            } else {
                return false;
            }
        }
        return node->isLeaf;
    }
    
    bool startsWith(string prefix) {
        TrieNode* node = trie;
        for (int i = 0; i < prefix.length(); i++) {
            if (node->children[prefix[i]-'a'] != NULL) {
                node = node->children[prefix[i]-'a'];
            } else {
                return false;
            }
        }
        return true;
    }
};
