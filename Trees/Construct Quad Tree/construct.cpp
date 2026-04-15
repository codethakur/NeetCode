/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
    bool isAllSame(vector<vector<int>>& grid, int row, int col, int n) {
        int first = grid[row][col];
        for (int i = row; i < row + n; i++) {
            for (int j = col; j < col + n; j++) {
                if (grid[i][j] != first)
                    return false;
            }
        }
        return true;
    }
    Node* solve(vector<vector<int>>& grid, int row, int col, int n) {
        if (isAllSame(grid, row, col, n)) {
            return new Node(grid[row][col] == 1, true);
        }

        int half = n / 2;

        return new Node(
            false, false,
            solve(grid, row, col, half),                    // topLeft
            solve(grid, row, col + half, half),             // topRight
            solve(grid, row + half, col, half),             // bottomLeft
            solve(grid, row + half, col + half, half)       // bottomRight
        );
    }

public:
    Node* construct(vector<vector<int>>& grid) {
        return solve(grid, 0, 0, grid.size());
    }
};
