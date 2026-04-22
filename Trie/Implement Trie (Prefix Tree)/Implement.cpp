struct TrieNodeArray
{
    TrieNodeArray* childrean[26] = {};
    bool isEndOfWord = false;
};

class PrefixTree {
    TrieNodeArray* root;
public:
    PrefixTree() {
          root = new TrieNodeArray(); 
    }
    
    void insert(string word) {
        TrieNodeArray* node = root;
        for(char ch : word)
        {
            int idx = ch - 'a';
            if(!node->childrean[idx])
                node->childrean[idx] = new TrieNodeArray();
            node = node->childrean[idx];
        }
        node->isEndOfWord = true;
    }
    
    bool search(string word) {
        TrieNodeArray* node = root;
        for(char ch : word)
        {
            int idx = ch - 'a';
            if(!node->childrean[idx]) return false;
            node = node->childrean[idx];
        }
        return node->isEndOfWord;
    }
    
    bool startsWith(string prefix) {
        TrieNodeArray* node = root;
        for(char ch : prefix)
        {
            int idx = ch - 'a';
            if(!node->childrean[idx]) return false;
            node = node->childrean[idx];
        }
        return true;
    }
};
