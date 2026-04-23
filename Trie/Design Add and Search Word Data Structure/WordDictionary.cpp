struct TrieNodeVec {
    std::vector<std::pair<char, TrieNodeVec*>> children;
    bool isEndOfWord = false;

    TrieNodeVec* getChild(char ch) {
        for (auto& [c, node] : children)
            if (c == ch) return node;
        return nullptr;
    }
};

class WordDictionary {
    bool dfs(TrieNodeVec* node, const string& word, int i) {
        if (i == (int)word.size())
            return node->isEndOfWord;

        char ch = word[i];

        if (ch == '.') {
            for (auto& [c, child] : node->children)
                if (dfs(child, word, i + 1)) return true;
            return false;                    
        } else {
            TrieNodeVec* child = node->getChild(ch);
            if (!child) return false;
            return dfs(child, word, i + 1);
        }
    }

public:
    TrieNodeVec* root;

    WordDictionary() { root = new TrieNodeVec(); }

    void addWord(const string& word) {
        TrieNodeVec* node = root;
        for (char ch : word) {
            TrieNodeVec* child = node->getChild(ch);
            if (!child) {
                child = new TrieNodeVec();
                node->children.push_back({ch, child});  
            }
            node = child;
        }
        node->isEndOfWord = true;                       
    }

    bool search(const string& word) {
        return dfs(root, word, 0);                     
    }
};
