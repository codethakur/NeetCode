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
