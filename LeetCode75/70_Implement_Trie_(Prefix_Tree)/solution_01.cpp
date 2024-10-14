class Trie {
    struct Node {
        Node* child[26];
        bool isEnd;
    };
    Node* root;
    Node* getNode() {
        Node* node = new Node();
        node->isEnd = false;
        for (int i = 0; i < 26; i++) {
            node->child[i] = NULL;
        }
        return node;
    }

public:
    Trie() { root = getNode(); }

    void insert(string word) {
        Node* cur = root;
        for (int i = 0; i < word.size(); i++) {
            int idx = word[i] - 'a';
            if (cur->child[idx] == NULL) {
                cur->child[idx] = getNode();
            }
            cur = cur->child[idx];
        }
        cur->isEnd = true;
    }

    bool search(string word) {
        Node* cur = root;
        for (int i = 0; i < word.size(); i++) {
            int idx = word[i] - 'a';
            if (cur->child[idx] == NULL) {
                return false;
            }
            cur = cur->child[idx];
        }
        return cur->isEnd;
    }

    bool startsWith(string prefix) {
        Node* cur = root;
        for (int i = 0; i < prefix.size(); i++) {
            int idx = prefix[i] - 'a';
            if (cur->child[idx] == NULL) {
                return false;
            }
            cur = cur->child[idx];
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
