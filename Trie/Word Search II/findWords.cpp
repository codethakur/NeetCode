class Solution {
    int m, n;
    bool dfs(vector<vector<char>>& board, const string& word, int i, int j, int idx) {
        if (idx == (int)word.size()) return true;
        if (i < 0 || i >= m || j < 0 || j >= n) return false;
        if (board[i][j] != word[idx]) return false;

        char temp = board[i][j];
        board[i][j] = '#';

        bool found = dfs(board, word, i+1, j, idx+1) ||
                     dfs(board, word, i-1, j, idx+1) ||
                     dfs(board, word, i, j+1, idx+1) ||
                     dfs(board, word, i, j-1, idx+1);

        board[i][j] = temp;
        return found;
    }

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        m = board.size();
        n = board[0].size();

        vector<string> output;

        for (const string& word : words) {
            bool wordFound = false;                      // ← flag for this word
            for (int i = 0; i < m && !wordFound; i++) { // ← stop outer loop too
                for (int j = 0; j < n && !wordFound; j++) {
                    if (board[i][j] == word[0]) {
                        if (dfs(board, word, i, j, 0)) {
                            output.push_back(word);
                            wordFound = true;            // ← breaks BOTH loops
                        }
                    }
                }
            }
        }

        return output;
        
    }
};

#if 0
struct TrieNode {
    TrieNode* children[26] = {};
    string word = "";            // stores full word at end node
};

class Solution {
    TrieNode* root;
    vector<string> output;
    int m, n;

    void addWord(const string& word) {
        TrieNode* node = root;
        for (char ch : word) {
            int idx = ch - 'a';
            if (!node->children[idx])
                node->children[idx] = new TrieNode();
            node = node->children[idx];
        }
        node->word = word;           // store full word at isEnd node
    }

    void dfs(vector<vector<char>>& board, int i, int j, TrieNode* node) {
        // out of bounds or visited
        if (i < 0 || i >= m || j < 0 || j >= n) return;
        if (board[i][j] == '#') return;

        char ch = board[i][j];
        int idx = ch - 'a';

        // Trie prune — no word possible down this path
        if (!node->children[idx]) return;

        node = node->children[idx];

        // word found
        if (node->word != "") {
            output.push_back(node->word);
            node->word = "";         // prevent duplicates
        }

        // mark visited
        board[i][j] = '#';

        // explore 4 directions — passing trie node down
        dfs(board, i+1, j, node);
        dfs(board, i-1, j, node);
        dfs(board, i, j+1, node);
        dfs(board, i, j-1, node);

        // backtrack
        board[i][j] = ch;
    }

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        root = new TrieNode();
        m = board.size();
        n = board[0].size();

        // build Trie — same as Extra Characters
        for (const string& word : words)
            addWord(word);

        // DFS from every cell — passing root node
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                dfs(board, i, j, root);

        return output;
    }
};
#endif
