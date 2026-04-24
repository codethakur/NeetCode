struct TrieNode {
    TrieNode* children[26] = {};
    bool isEnd = false;
};

class Solution {
    TrieNode* root;

    void addWord(const string& word) {
        TrieNode* node = root;
        // insert REVERSED — so we can walk backwards in s
        for (int i = word.size() - 1; i >= 0; i--) {
            int idx = word[i] - 'a';
            if (!node->children[idx])
                node->children[idx] = new TrieNode();
            node = node->children[idx];
        }
        node->isEnd = true;
    }

public:
    int minExtraChar(string s, vector<string>& dictionary) {
        root = new TrieNode();

        // build trie with all dictionary words (reversed)
        for (const string& word : dictionary)
            addWord(word);

        int n = s.size();
        vector<int> dp(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            // option 1: skip s[i-1]
            dp[i] = dp[i - 1] + 1;

            // option 2: walk trie backwards from i-1
            TrieNode* node = root;
            for (int j = i - 1; j >= 0; j--) {
                int idx = s[j] - 'a';
                if (!node->children[idx]) break; // no word possible
                node = node->children[idx];
                if (node->isEnd)                 // word s[j..i-1] found
                    dp[i] = min(dp[i], dp[j]);
            }
        }

        return dp[n];
    }
};
