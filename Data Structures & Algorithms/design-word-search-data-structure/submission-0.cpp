class Trie {

public:
    Trie *node[26];
    bool isEnd;

    Trie() {
        isEnd = false;
        for (int i = 0; i < 26; i++) {
            node[i] = NULL;
        }
    }
};

class WordDictionary {
public:
    Trie *trie;
    WordDictionary() {
        trie = new Trie();
    }
    
    void addWord(string word) {
        Trie *ptr = trie;
        for (int i = 0; i < word.length(); i++) {
            if (!ptr->node[word[i] - 'a']) {
                ptr->node[word[i] - 'a'] = new Trie();
                ptr = ptr->node[word[i] - 'a'];
            } else {
                ptr = ptr->node[word[i] - 'a'];
            }
        }
        ptr->isEnd = true;
    }
    
    bool search(string word) {
        return find(trie, word, 0);
    }

    bool find(Trie *node, string &word, int index) {
        if (index == word.length()) {
            if (node->isEnd) {
                return true;
            } else {
                return false;
            }
        }
        if (word[index] == '.') {
            for (int i = 0; i < 26; i++) {
                if (node->node[i]) {
                    if (find(node->node[i], word, index+1)) {
                        return true;
                    }
                }
            }
        } else {
            if (node->node[word[index] - 'a']) {
                return find(node->node[word[index] - 'a'], word, index+1);
            }
        }
        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */