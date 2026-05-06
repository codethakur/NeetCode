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
