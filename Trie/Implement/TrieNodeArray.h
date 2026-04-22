#include<iostream>
#include<string>
struct TrieNodeArray
{
    TrieNodeArray* childrean[26] = {};
    bool isEndOfWord = false;
};

class TrieArray
{
    TrieNodeArray* root;
public:
    TrieArray()
    {
        root = new TrieNodeArray(); 
    }

    void insert(const std::string& word)
    {
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

    bool search(const std::string& word)
    {
        TrieNodeArray* node = root;
        for(char ch : word)
        {
            int idx = ch - 'a';
            if(!node->childrean[idx]) return false;
            node = node->childrean[idx];
        }
        return node->isEndOfWord;
    }
    bool startsWith(const std::string& prefix) 
    {
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

