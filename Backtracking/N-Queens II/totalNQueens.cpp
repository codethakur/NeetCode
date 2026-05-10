#if 0
class Solution {
public:
    int totalNQueens(int n) {
        int count = 0;
        struct Frame {
            int row;
            vector<bool> col;
            vector<bool> diag1;
            vector<bool> diag2;
        };

        stack<Frame>st;
        st.push({0, vector<bool>(n, false), vector<bool>(2 * n - 1, false),   vector<bool>(2 * n - 1, false)});

        while(!st.empty())
        {
            auto[row, usedCol, diag1, diag2] = st.top();
            st.pop();

            if(row == n)
            {
                count++;
                continue;
            }

            for(int col = n-1; col>=0; col--)
            {
                int d1 = row - col + n-1;
                int d2 = row + col;

                // invalid position
                if (usedCol[col] ||
                    diag1[d1] ||
                    diag2[d2])
                    continue;
                
                auto nextUsedCol = usedCol;
                auto nextdiag1 = diag1;
                auto nextdiag2 = diag2;

                nextUsedCol[col] = true;
                nextdiag1[d1] = true;
                nextdiag2[d2] = true;

                st.push({row+1, nextUsedCol, nextdiag1, nextdiag2});
            }
        }
        return count;
    }
};
#endif

class Solution {
    void dfs(int n, int row, vector<bool>& col, vector<bool>&diag1, vector<bool>&diag2, int& count)
    {
        if(row == n){
            count++;
            return;
        }
        for(int j = 0; j<n; j++)
        {
            int d1 = row - j + n-1;
            int d2 = row + j;
            if (col[j] || diag1[d1] || diag2[d2]) continue;

            col[j] = true;
            diag1[d1] = true;
            diag2[d2] = true;
            
            dfs(n, row + 1, col, diag1, diag2, count);

            col[j] = false;
            diag1[d1] = false;
            diag2[d2] = false;
 
        }
    }
public:
    int totalNQueens(int n) {
        int count = 0;
        int row;
        vector<bool> col(n, false);
        vector<bool> diag1( 2 * n - 1, false);
        vector<bool> diag2( 2 * n - 1, false);
        dfs(n,0, col, diag1, diag2, count);

        return count;
    }
};
