#include <iostream>
#include <unordered_map>
#include <string>

struct TrieNodeMap 
{
    std::unordered_map<char, TrieNodeMap*>children;
    bool isEndOfWord = false;
};

class TrieMap
{
    TrieNodeMap* root;
public:
    TrieMap() { root = new TrieNodeMap();}

    void insert(const std::string& word)
    {
        TrieNodeMap* node = root;

        for(auto ch : word)
        {
            if(!node->children.count(ch)){
                node->children[ch] = new TrieNodeMap();
            }
              node = node->children[ch];
        }
        node->isEndOfWord = true;
    }

    bool search(const std::string& word) 
    {
        TrieNodeMap* node = root;

        for(auto ch : word)
        {
            if(!node->children.count(ch))return false;
            node = node->children[ch];
        }
        return node->isEndOfWord;
    }
    bool startsWith(const std::string& prefix) 
    {
        TrieNodeMap* node = root;

        for(auto ch : prefix)
        {
            if(!node->children.count(ch))return false;
            node = node->children[ch];
        }
        return true;
    }
};
