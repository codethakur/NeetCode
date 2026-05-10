class Solution {
public:

    vector<vector<string>> solveNQueens(int n) {

        vector<vector<string>> ans;

        struct Frame {

            int row;

            vector<string> board;

            vector<bool> col;
            vector<bool> diag1;
            vector<bool> diag2;
        };

        stack<Frame> st;

        // initial empty board
        vector<string> emptyBoard(
            n,
            string(n, '.')
        );

        st.push({
            0,
            emptyBoard,
            vector<bool>(n, false),
            vector<bool>(2 * n - 1, false),
            vector<bool>(2 * n - 1, false)
        });

        while (!st.empty()) {

            auto [row,
                  board,
                  colUsed,
                  diag1,
                  diag2] = st.top();

            st.pop();

            // all queens placed
            if (row == n) {
                ans.push_back(board);
                continue;
            }

            // try every column
            for (int col = n - 1; col >= 0; col--) {

                int d1 = row - col + n - 1;
                int d2 = row + col;

                // invalid placement
                if (colUsed[col] ||
                    diag1[d1] ||
                    diag2[d2])
                    continue;

                // create next state
                auto nextBoard = board;
                auto nextCol = colUsed;
                auto nextDiag1 = diag1;
                auto nextDiag2 = diag2;

                // place queen
                nextBoard[row][col] = 'Q';

                // mark attacks
                nextCol[col] = true;
                nextDiag1[d1] = true;
                nextDiag2[d2] = true;

                // next row
                st.push({
                    row + 1,
                    nextBoard,
                    nextCol,
                    nextDiag1,
                    nextDiag2
                });
            }
        }

        return ans;
    }
};
