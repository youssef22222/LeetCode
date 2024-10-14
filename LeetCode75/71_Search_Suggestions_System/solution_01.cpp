class Trie {
    struct Node {
        Node* child[26];
        bool isEnd;
        priority_queue<string> pq;
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
            if (cur->pq.size() == 3) {
                if (cur->pq.top() > word) {
                    cur->pq.pop();
                    cur->pq.push(word);
                }
            } else {
                cur->pq.push(word);
            }
        }
        cur->isEnd = true;
    }
    vector<string> startsWith(string prefix) {
        Node* cur = root;
        vector<string> strs;
        for (int i = 0; i < prefix.size(); i++) {
            int idx = prefix[i] - 'a';
            if (cur->child[idx] == NULL) {
                return strs;
            }
            cur = cur->child[idx];
        }
        while (cur->pq.size()) {
            strs.push_back(cur->pq.top());
            cur->pq.pop();
        }
        reverse(strs.begin(), strs.end());
        return strs;
    }
};

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        Trie* trie = new Trie();
        for (auto it : products) {
            trie->insert(it);
        }
        vector<vector<string>> ans;
        for (int i = 0; i < searchWord.size(); i++) {
            ans.push_back(trie->startsWith(searchWord.substr(0, i + 1)));
        }
        return ans;
    }
};
