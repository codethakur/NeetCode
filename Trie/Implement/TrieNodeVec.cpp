#include <vector>
#include <string>

struct TrieNodeVec {
    std::vector<std::pair<char, TrieNodeVec*>> children;
    bool isEndOfWord = false;

    TrieNodeVec* getChild(char ch) {
        for (auto& [c, node] : children)
            if (c == ch) return node;
        return nullptr;
    }
};

class TrieVec {
    TrieNodeVec* root;
public:
    TrieVec() { root = new TrieNodeVec(); }

    void insert(const std::string& word) {
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

    bool search(const std::string& word) {
        TrieNodeVec* node = root;
        for (char ch : word) {
            TrieNodeVec* child = node->getChild(ch);
            if (!child) return false;
            node = child;
        }
        return node->isEndOfWord;  
    }

    bool startsWith(const std::string& prefix) {
        TrieNodeVec* node = root;
        for (char ch : prefix) {
            TrieNodeVec* child = node->getChild(ch);
            if (!child) return false;
            node = child;
        }
        return true;
    }
};
