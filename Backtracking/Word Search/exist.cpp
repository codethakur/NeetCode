#if 0
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();   
        int cols = board[0].size(); 
        struct Frame
        {
            int r, c, idx;
            vector<vector<bool>>visited;
        };

        stack<Frame>st;

        for(int r = 0; r<rows; r++)
        {
            for(int c = 0; c<cols; c++)
            {
                if(board[r][c] != word[0]) continue;

                vector<vector<bool>> vis(rows, vector<bool>(cols, false));
                vis[r][c] = true;
                st.push({r, c, 0, vis});
            }
        }
        vector<pair<int, int>>dir = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} } ;
        while(!st.empty())
        {
            auto[r, c, idx, visited] = st.top();
            st.pop();

            if(idx == word.size()-1){
                return true;
            }
            for(auto[dr, dc] : dir)
            {
                int nr = r+dr;
                int nc = c+dc;

                if(nr < 0 || nr >= rows || nc < 0 || nc >= cols) continue;

                if(visited[nr][nc]) continue;

                if(board[nr][nc] != word[idx+1]) continue;

               auto nextVisited = visited;
               nextVisited[nr][nc] = true;
               st.push({nr, nc, idx+1, nextVisited});
            }
        }
        return false;

    }
};
#endif 
class Solution {
    bool dfs(vector<vector<char>>& board, string& word, int r, int c, int idx)
    {
        // whole word matched
        if(idx == word.size()){
            return true;
        }
        int rows =  board.size();
        int cols =  board[0].size();
        // bounds
        if(r<0 || c<0 || r >= rows || c>=cols ) return false;
        // mismatch
        if (board[r][c] != word[idx]) return false;
        // already used
        if(board[r][c] == '#') return false;

        // save original char
        char temp = board[r][c];
        // mark visited
        board[r][c] = '#';
        // explore 4 directions
        bool found = (dfs(board, word, r+1, c, idx+1) ||
                    dfs(board, word, r-1, c, idx+1) ||
                    dfs(board, word, r, c+1, idx+1) ||
                    dfs(board, word, r, c-1, idx+1) );
       // BACKTRACK (undo)
        board[r][c] = temp;
        return found;

    } 
public:
    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int cols = board[0].size();

        for(int r = 0; r<rows; r++)
        {
            for(int c = 0; c<cols; c++)
            {
                if(board[r][c] == word[0])
                {
                    if(dfs(board, word, r, c, 0))
                        return true;

                }
            }
        }
        return false;
    }
};
